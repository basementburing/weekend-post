//反向建图用 迪杰斯特做即可
//题目链接：https://vjudge.net/contest/295278#problem/A
#include<iostream>
#include<algorithm>
#include<cstring>
#define inf 0x3f3f3f3f
using namespace std;
int map[1010][1010];
int dis[1010];
int vis[1010];
int n,m,s;
void djs(int s){
	memset(dis,inf,sizeof(dis));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		if(i == s) vis[i] = 1;
		if(map[s][i]<inf)dis[i] = map[s][i];
	}
	int min,v;
	for(int i=1;i<=n;i++){
		min = inf;
		v=-1;
		for(int j=1;j<=n;j++){
			if(vis[j]==0&&dis[j]<min){
				min = dis[j];
			    v = j;	
			}
		}
		if(v == -1)continue;
		vis[v] = 1;
		for(int j=1;j<=n;j++){
			if(vis[j]==0&&dis[v]+map[v][j]<dis[j])dis[j]=dis[v]+map[v][j];
		}
	}
	
} 
int main(){
	while(~scanf("%d %d %d",&n,&m,&s)){
		memset(map,inf,sizeof(map));
		for(int i = 0;i<m;i++){
			int temp1,temp2,temp3;
			scanf("%d %d %d",&temp1,&temp2,&temp3);
			map[temp2][temp1] = min(map[temp2][temp1],temp3);
		}
		djs(s);
		int n;
		int ans = inf;
		cin>>n;
		for(int i=0;i<n;i++){
			int e;
			scanf("%d",&e);
			ans =min(ans,dis[e]);
		}
		if(ans==inf)cout<<-1<<endl;
		else cout<<ans<<endl;
	}
}