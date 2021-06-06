//judge.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "common.h"
void judge (int num,int count,char *str1,char *str2,int *flag1,int *flag2){
//判断输入个数是否符合
    if (num!=3){
        usage();
    }
    //判断两个蛋白质是否在文件中,同时得到了flag1和flag2的值。
	
    int p;
    
    
    for (p=1;p<=count;p++){
    if (strcmp(str1,pro[p])==0){
    *flag1=p;
    break;}    
    }
    for (p=1;p<=count;p++){
    if (strcmp(str2,pro[p])==0){
    *flag2=p;
    break;}    
    }
    if (*flag1==0||*flag2==0){
        usage();    
    }    
    
}
