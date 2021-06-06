//Bellman_Ford.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "common.h"
#define maxint 99999
typedef struct Edge
{
    int start, end;   
    int weight;  
} Edge;
Edge * edge;     
int  * dist;
int  * pre;  


_Bool Bellman_Ford(int nodenum,int edgenum)
{	int i,j;
    for( i = 1; i <= nodenum-1; ++i)
        for(j = 0; j < edgenum; ++j)
 {
           if(dist[edge[j].end] > dist[edge[j].start] + edge[j].weight)
         {
             dist[edge[j].end] = dist[edge[j].start] + edge[j].weight;
             pre[edge[j].end] = edge[j].start;//用到pre，这个数组的意思是，从后面的指向前面的方向，由于不可能存在两个指向同一个，所以该算法是成立的。
         }  
 }
    _Bool flag = 1;
   
    for(i = 0; i <edgenum; ++i)
        if(dist[edge[i].end] > dist[edge[i].start] + edge[i].weight)
        {
            flag = 0;
            break;
        }
    return flag;
}

void print_path(int root)  //前驱的打印函数，用到pre
{  
    while(root!=pre[root])  
    {  
        printf("\033[0;34m%s-->\033[0;34m", pro[root]);  
        root = pre[root];  
    }  
    if(root == pre[root])  
        printf("\033[0;34m%s\n\033[0;34m", pro[root]);  
} 
int main (int argc, char *argv[ ]) {
	
    char input[100];
    puts("please input your protein net file");
    scanf("%s",input);
    num_protein_make(input);
    int count;
    count = array_make();
   	int flag1,flag2;
    judge (argc,count,argv[1],argv[2], &flag1, &flag2);
    int count2;
    count2=creat_new(input,count);
/*此时在后续算法中可能要用的内容分别如下：
 count : 蛋白质个数
 count2:对应关系个数
 flag1:出发蛋白编号
 flag2:终止蛋白编号
 */
    
    
//然后我得到的程序要和张扬得到的做接口，所以要换算成他使用的变量。
    int i;
	int nodenum,edgenum;//
    FILE *fp;
	
	nodenum=count;
	edgenum=count2;
	int source,end;
    source=flag1;
    end=flag2;
    int p,j;
	//使用malloc给外面定义的全局指针赋空间，以便在其它函数中使用。
    edge=(Edge *)malloc(sizeof(Edge)*edgenum);
    dist=(int *)malloc(sizeof(int)*nodenum);
    pre=(int *)malloc(sizeof(int)*nodenum);
    //给dist函数赋初值
    for(i = 1; i <= nodenum; ++i)
        dist[i] = maxint;
    dist[source] = 0;
    int q=0;
    i=0;
    fp=fopen("new.txt", "rt+");
    if(fp==NULL)             /*判断文件是否打开成功*/
             puts("File new.txt to read  open error\n");/*提示打开不成功*/
    while(!feof(fp)){
  	
        fscanf(fp,"%d %d %d\n",&p,&q,&j);
 	edge[i].start = p;
 	edge[i].end = q;
 	edge[i].weight = j;
 	if(edge[i].start == source)  {        
            dist[edge[i].end] = edge[i].weight;
        	pre[edge[i].end]=source;
    }
  	i++;
      }//从0开始的edge
    i=fclose(fp);            /*关闭打开的文件*/
    if(i==0)                 /*判断文件是否关闭成功*/
        printf("File new.txt to read close correctly \n");         /*提示关闭成功*/
    else
        puts("File new.txt to read close error\n");/*提示关闭不成功*/
    pre[source] = source;
    
    
    if(Bellman_Ford(nodenum,edgenum)){
        	if (dist[end]>90000){
                printf("There is no way to link %s and %s\n",pro[source],pro[end]);
                return 0;
            }
            printf("\033[0;34mThe shortest way score is %d\n\033[0;34m",dist[end]);//最终坐标
     		printf("\033[0;34mPath:\n\033[0;34m");  
            print_path(end);//最终坐标
     } 
    else  
        printf("have negative circle\n");
    free(edge);
 	free(dist);
 	free(pre);
    printf("\033[0m");
       
    return 0;
}

