//Dijkstra.cpp
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<fstream>
#include<stack>
#include<queue>
#include<cstring>
#include<map>
#include<iterator>
#include<list>
#include<set>
#include<functional>
#include<memory.h>
#include "Dijkstra.h"

using namespace std;

const int maxn=1e4;
const int M=1e7;
const int inf=0x3f3f3f3f;
typedef struct Edge{
	int next;
	int to;
	int w;
}Edge;
Edge edge[M];
int head[maxn];
//int  *pre; 
bool visited[maxn];
typedef pair<int,int> pll;
int dis[maxn];
void init(){
	memset(visited,false,sizeof(visited));
	memset(dis,inf,sizeof(dis));
	memset(head,-1,sizeof(head));
}
int n,m;
int cnt;
void add(int u,int v,int w){

	edge[cnt].to=v;
	edge[cnt].w=w;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}


void dijkstra(int S,int *pre){
	priority_queue<pll,vector<pll>,greater<pll> > q;
	dis[S]=0;
	q.push(pll(0,S));
	pll temp;
	cnt=0;
	while(!q.empty()){
		temp=q.top();
		q.pop();
		int u=temp.second;
		if(visited[u])continue;
		visited[u]=true;
		int t,len;
		for(int i=head[u];i!=-1;i=edge[i].next){
			t=edge[i].to;len=edge[i].w;
			if(!visited[t]&&dis[t]>dis[u]+len){
				dis[t]=dis[u]+len;
				pre[t]=u;//shabi
				q.push(pll(dis[t],t));
			}
		}
	}
}


void print_path(int root,int *pre)  
{  
    while(root!=pre[root])  
    {  
        cout<<pro[root]<<"-->";  
        root = pre[root];  
    }  
    if(root == pre[root])  
        cout<<pro[root]<<endl;  
} 

int main(int argc, char *argv[ ]){
	//while(cin>>n>>m){
		//int u,v,w;
		//init();
		//for(int i=0;i<m;i++){
			//cin>>u>>v>>w;
			//add(u,v,w);
			//add(v,u,w);
		//}
    //利用接口的预处理
    char input[100];
    cout << "please input your protein net file\n";
    cin>>input;
    
    num_protein_make(input);
    int count;
    count = array_make();
   	int flag1,flag2;
    judge (argc,count,argv[1],argv[2], &flag1, &flag2);
    int count2;
    count2=creat_new(input,count);

	
	int n,m;
	n=count;
    m=count2;
	//pre=(int *)malloc(sizeof(int)*n);
	int *pre=new int[n];
	int u,v,w;
	init();
	ifstream infile;  
    	//ofstream outfile;   
 	infile.open("new.txt", ios::in); 
    if(!infile.is_open ())
        cout << "Open file failure" << endl;
    while (!infile.eof())           
    {
        infile >> u >> v >> w;
        add(u,v,w);
	add(v,u,w);               
    }
    infile.close(); 

	
		int S,E;
		S=flag1;
    	E=flag2;
		pre[S]=S;
		
		dijkstra(S,pre);
	


		cout<< "the shortest way score is " <<dis[E]<<endl;
		cout<<"Path: "<<endl;
		print_path(E,pre);
		
	
	delete[] pre;
	return 0;
}
