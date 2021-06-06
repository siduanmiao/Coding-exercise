//num_protein_make.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "common.h"
//生成编号-蛋白质对应文件以便生成对应数组
void num_protein_make (char *input){
    
    int i;
    
    
    
//初始化    
   	int pls=0;
	char *s=(char*)malloc(25*sizeof(char));
	char *t=(char*)malloc(25*sizeof(char));
	char **z=(char**)malloc(10000*sizeof(char*));
    char tmp[100];
    for(pls=0;pls<10000;pls++){
        z[pls]=(char *)malloc(25*sizeof(char));    
    }
    
    
//读写
    FILE *fp1;
	FILE *fp2;
    
	int i1=0,j1=1,m1,pos;
	fp1=fopen(input,"r");
	fp2=fopen("num_protein.txt","w");
    if(fp1==NULL)             /*判断文件是否打开成功*/
             puts("File input open error\n");/*提示打开不成功*/
    if(fp2==NULL)             /*判断文件是否打开成功*/
             puts("File num_protein.txt open to write error\n");/*提示打开不成功*/
    //将文件第一行的内容吃掉
    fgets(tmp,100,fp1);
    
	while (!feof(fp1)){
		fscanf(fp1,"%s\t%s\t%d\n",s,t,&j1);
		for(m1=0;m1<i1;m1++){
			if(strcmp(z[m1],s)==0)  break;
        	}
		if(m1==i1) {
            strcpy(z[i1],s);
			pos=i1+1;
			fprintf(fp2,"%d %s\n",pos,s);
            i1=i1+1;
		}
		for(m1=0;m1<i1;m1++){
			if(strcmp(z[m1],t)==0) break;
        }
		if(m1==i1) {
			strcpy(z[i1],t);
            pos=i1+1;
			fprintf(fp2,"%d %s\n",pos,t);
			i1=i1+1;
			}
    	}
    
    
    
	i=fclose(fp1);            /*关闭打开的文件*/
    if(i==0)                 /*判断文件是否关闭成功*/
        printf("File input close correctly \n");         /*提示关闭成功*/
    else
        puts("File input close error\n");/*提示关闭不成功*/
    i=fclose(fp2);            /*关闭打开的文件*/
    if(i==0)                 /*判断文件是否关闭成功*/
        printf("File  num_protein.txt open to write close correctly \n");         /*提示关闭成功*/
    else
        puts("File num_protein.txt open to write close error\n");/*提示关闭不成功*/
   	free(s);
 	free(t);
 	free(z);
        
}
