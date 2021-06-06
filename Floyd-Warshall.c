//Floyd-Warshall.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "common.h"
#define maxint 99999
//还有pro函数指着对应关系。
int **pre;
void print_path(int source,int end,FILE* fp)  //前驱的打印函数，用到pre
{  	
    fprintf(fp,"%s-->", pro[end]);
    while(pre[source][end]!=source)  
        
    {  	end = pre[source][end]; 
        fprintf(fp,"%s-->", pro[end]);  
         
    }  
    if(pre[source][end]==source)  
        fprintf(fp,"%s\n", pro[source]);  
} 



int main () {
	
    char input[100];
    puts("please input your protein net file");
    scanf("%s",input);
    num_protein_make(input);
    int count;
    count = array_make();
   	/*int flag1,flag2;
    judge (argc,count,argv[1],argv[2], &flag1, &flag2);*/
    int count2;
    count2=creat_new(input,count);
/*此时在后续算法中可能要用的内容分别如下：
 count : 蛋白质个数
 count2:对应关系个数
 */
    
    int i=0;
//然后写我自己的算法，因为我们默认的是10000个以下的蛋白质数量，所以不需要设置动态大小
    int** Farray =(int**)malloc(10000*sizeof(int*));
    pre=(int**)malloc(10000*sizeof(int*));
    for(i=1;i<10000;i++){
        Farray[i]=(int *)malloc(10000*sizeof(int));
        
    }
     for(i=1;i<10000;i++){
        pre[i]=(int *)malloc(10000*sizeof(int));
        
    }
    
    
    
    
    
    int j=0;
    for (i=1;i<10000;++i){
		for(j=1;j<10000;++j){
            Farray[i][j]=maxint;
            pre[i][j]=-1;
        }        
        
    }
    int p;
    int q;
    
    FILE *fp;
    fp=fopen("new.txt", "rt+");
    if(fp==NULL)             /*判断文件是否打开成功*/
             puts("File new.txt to read  open error\n");/*提示打开不成功*/
    while(!feof(fp)){
  	
        fscanf(fp,"%d %d %d\n",&p,&q,&j);
 		Farray[p][q]=j;
        pre[p][q]=p;
        
        
        
        
      }//注意这里是从1开始的
    i=fclose(fp);            /*关闭打开的文件*/
    if(i==0)                 /*判断文件是否关闭成功*/
        printf("File new.txt to read close correctly \n");         /*提示关闭成功*/
    else
        puts("File new.txt to read close error\n");/*提示关闭不成功*/
    //p是节点
    for(p=1;p<=count;p++){
        for(i=1;i<=count;i++){
            for(j=1;j<=count;j++){
                if(Farray[i][j]>Farray[i][p]+Farray[p][j]){
                    Farray[i][j]=Farray[i][p]+Farray[p][j];
                    pre[i][j]=p;
                }    
            }
        }
    }
    
    //然后从文件中读入想要查找的蛋白质名称
    //然后尝试输出最终结果看一看
   	puts("please input the protein filename:");
    char filename[100];
    scanf("%s",filename);
    int flag1,flag2;
    char name1[100];
    char name2[100];
    
    fp=fopen(filename, "rt+");
    if(fp==NULL)             /*判断文件是否打开成功*/
             puts("protein filename to read  open error\n");/*提示打开不成功*/
    FILE *fp3=fopen("result.txt", "w");
     while(!feof(fp)){
  		fscanf(fp,"%s %s\n",name1,name2);
        judge (3,count,name1,name2, &flag1, &flag2);
        fprintf(fp3,">> %s %s %d\n",name1,name2,Farray[flag1][flag2]);
        print_path(flag1,flag2,fp3);
        
      }//注意这里是从1开始的
    i=fclose(fp);            /*关闭打开的文件*/
    if(i==0)                 /*判断文件是否关闭成功*/
        printf("protein filename to read close correctly \n");         /*提示关闭成功*/
    else
        puts("protein filename read close error\n");/*提示关闭不成功*/
    
    i=fclose(fp3);            /*关闭打开的文件*/
    if(i==0)                 /*判断文件是否关闭成功*/
        printf("result.txt close correctly \n");         /*提示关闭成功*/
    else
        puts("result.txt close error\n");/*提示关闭不成功*/
    
 
    free(Farray);
     
    return 0;
}
