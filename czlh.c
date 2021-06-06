//龙浩--生成蛋白质对应关系
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    //设置文件指针
	FILE *fp1;
	FILE *fp2;
    int pls=0;
	char *s=(char*)malloc(25*sizeof(char));
	char *t=(char*)malloc(25*sizeof(char));
	char **z=(char**)malloc(10000*sizeof(char*));
    char tmp[100];
    for(pls=0;pls<10000;pls++){
        z[pls]=(char *)malloc(25*sizeof(char));
        
        
    }
    
    
    
	int i1=0,j1=1,m1,pos;
	fp1=fopen("1504319.protein.links.v11.0.txt","r");
	fp2=fopen("bigwork1.txt","w");
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
	fclose(fp1);
	fclose(fp2);
	return 0;
}
