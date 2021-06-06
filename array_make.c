//生成数组
//array_make.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "common.h"
char pro[10000][25];
int array_make () {

	int j;
    int i;
	int count=1;
    
 	FILE *fp;                     /*定义文件指针*/
    fp=fopen("num_protein.txt", "r");
    if(fp==NULL)             /*判断文件是否打开成功*/
             puts("File num_protein.txt open to read error\n");/*提示打开不成功*/
    //创建数组
   
	while(!feof(fp)){
        
        fscanf(fp,"%d %s\n",&j,pro[count]);
        count++;
        
    }
    count--;
    //得到了一个由1开始的编号与名称的对应数组
    
    i=fclose(fp);            /*关闭打开的文件*/
    if(i==0)                 /*判断文件是否关闭成功*/
        printf("File  num_protein.txt open to read close correctly \n");         /*提示关闭成功*/
    else
        puts("File num_protein.txt open to read close error\n");/*提示关闭不成功*/
    return count;
    
}
