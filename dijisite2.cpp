//没什么技巧 直接套djs
//题目链接：https://vjudge.net/contest/295278#problem/B
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define inf 0x3fffffff
using namespace std;
int map[1010][1010],dis[1010],vis[1010],n,m;
void djs(int n){
	memset(dis,inf,sizeof(dis));
	memset(vis,0,sizeof(vis));
	for(int i=0;i<=n;i++){
	       dis[i] = map[1][i];
	}
	vis[1]=1;
	dis[1]=0;
	for(int i=1;i<=n;i++){
		int min = inf,v = -1;
		for(int j=1;j<=n;j++){
			if(vis[j]==0&&dis[j]<min){
				min= dis[j];
				v = j;
			}
		}
		if(v==-1)continue;
		vis[v] = 1;
		for(int j=1;j<=n;j++){
			if(vis[j]==0&&dis[v]+map[v][j]<dis[j])dis[j]=map[v][j]+dis[v];
		}
	}
}
int main(){
	scanf("%d %d",&m,&n);
		int to,from,cost;
		for(int i=1;i<=n;i++){            
		    map[i][i]=0;
            for(int j=1;j<i;j++)
            map[i][j]=map[j][i]=inf;
        }
		for(int i=0;i<m;i++){
			cin>>to>>from>>cost;
			if(cost<map[to][from]){
				map[to][from]=map[from][to]=cost;
			}
		}
		
		djs(n);
		cout<<dis[n]<<endl;
	
}