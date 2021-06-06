//creat_new.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "common.h"
int creat_new(char *input,int count){
	int count2=1;//作为后续算法使用的内容.
    FILE *fp1;
	FILE *fp2;
    char *s=(char*)malloc(25*sizeof(char));
	char *t=(char*)malloc(25*sizeof(char));
	int j1;
    char tmp[100];
    int i;
	fp1=fopen(input,"r");
    fp2=fopen("new.txt","w");
    if(fp1==NULL)             /*判断文件是否打开成功*/
             puts("File input to creat new.txt open error\n");/*提示打开不成功*/
    if(fp2==NULL)             /*判断文件是否打开成功*/
             puts("File new.txt open to write error\n");/*提示打开不成功*/
    
    fgets(tmp,100,fp1);
    int x,y;
   	while (!feof(fp1)){
		fscanf(fp1,"%s\t%s\t%d\n",s,t,&j1);
   		for(i=1;i<=count;i++){
            if (strcmp(s,pro[i])==0) x=i; 
            
        }
        for(i=1;i<=count;i++){
            if (strcmp(t,pro[i])==0) y=i; 
            
        }
        fprintf(fp2,"%d %d %d\n",x,y,j1);
        count2++;
      
    }
    count2--;
    i=fclose(fp1);            /*关闭打开的文件*/
    if(i==0)                 /*判断文件是否关闭成功*/
        printf("File input to creat new.txt close correctly \n");         /*提示关闭成功*/
    else
        puts("File input to creat new.txt close error\n");/*提示关闭不成功*/
    i=fclose(fp2);            /*关闭打开的文件*/
    if(i==0)                 /*判断文件是否关闭成功*/
        printf("File  new.txt open to write close correctly \n");         /*提示关闭成功*/
    else
        puts("File new.txt open to write close error\n");/*提示关闭不成功*/
    return count2;
}
