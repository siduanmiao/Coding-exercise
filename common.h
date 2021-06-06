//common.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#ifndef COMMON_H_now
#define COMMON_H_now
extern char pro[10000][25];
void usage ();
void num_protein_make (char *input);
void judge (int num,int count,char *str1,char *str2,int *flag1,int *flag2);
int array_make();
int creat_new(char *input,int count);

#endif
