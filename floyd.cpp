//因为这道题的数据规模 可以使用n^3的floyd算法 用map构建邻接图即可
//题目链接：https://vjudge.net/contest/295278#problem/D
#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<map>
using namespace std;
double map1[40][40];
map<string,int>name;
bool floyd(int n){
    for(int k=0;k<n;k++)
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        if(map1[i][j] < map1[i][k]*map1[k][j])
           map1[i][j] = map1[i][k]*map1[k][j];
	}
	for(int i=0;i<n;i++){
		if(map1[i][i]>1)return true;
	}
	 return false;
}
int main(){
	int n,m;
	int count = 1;
	while(~scanf("%d",&n)){
		if(n==0)break;
		for(int i=0;i<n;i++){
			string temp;
			cin>>temp;
			name[temp] = i;
		}
		scanf("%d",&m);
		memset(map1,0,sizeof(map1));
		for(int i=0;i<n;i++){
			map1[i][i] = 1;
		}
		for(int i=0;i<m;i++){
			string tmp1,tmp2;
			double ret;
			cin>>tmp1>>ret>>tmp2;
			//cout<<name[tmp1]<<" "<<name[tmp2]<<endl;
			map1[name[tmp1]][name[tmp2]] = ret;
		}
		if(floyd(n))cout<<"Case "<<count<<":"<<" Yes"<<endl;
		else cout<<"Case "<<count<<":"<<" No"<<endl;
	    count++;
		
	}
}