//读懂题目后发现只要找到正权环 对bellman算法稍微操作即可
//题目链接：https://vjudge.net/contest/295278#problem/C
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
struct Edge{
	int from;
	int to;
	double rent;
	double exart;
	int next;
}edge[210];

int tot = 0;
void add(int from,int to,double a,double b,double c,double d){
	edge[tot].to = to;
	edge[tot].from = from;
	edge[tot].rent = a;
	edge[tot].exart = b;

	tot++;
	edge[tot].from = to;
	edge[tot].to = from;
	edge[tot].rent = c;
	edge[tot].exart = d;
	
	tot++;
}
double dis[110];
bool bellman(int s,double sum,int m,int n){
	memset(dis,0,sizeof(dis));
	dis[s] = sum;
	for(int i=1;i<=n-1;i++){
		
		for(int j = 0;j<m;j++){
			if((edge[j].rent*(dis[edge[j].from]-edge[j].exart))>dis[edge[j].to]){
				dis[edge[j].to] = (edge[j].rent*(dis[edge[j].from]-edge[j].exart));
			
			}
		}
		
	}
	for(int j = 0;j<m;j++){
			if((edge[j].rent*(dis[edge[j].from]-edge[j].exart))>dis[edge[j].to]){
				return true;
	}
	 
   }
   return false;
}
int main(){
	int n,m,s;
	double sum;
	cin>>n>>m>>s>>sum;
	for(int i=0;i<m;i++){
		int from,to;
		double a,b,c,d;
		scanf("%d%d%lf%lf%lf%lf",&from,&to,&a,&b,&c,&d);
		add(from,to,a,b,c,d);
	}
	if(bellman(s,sum,tot,n)==1)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
}