#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
ll read(){
    ll f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
int n,m,k;
int link[220],vis[220],f[220][220];
int dfs(int x){
	for(int i=1;i<=n;i++){
		if(f[x][i] && !vis[i]){
			vis[i]=1;
			if(!link[i] || dfs(link[i])){
				link[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
int find(){
	memset(link,0,sizeof(link));
	int cnt=0;
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		if(dfs(i))cnt++;
	}
	return cnt;
}
int main(){
	while(~scanf("%d",&n)){
		if(!n)break;
		scanf("%d%d",&m,&k);
		memset(f,0,sizeof(f));
		for(int i=1;i<=k;i++){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			if(y && z){
				f[y][z]=1;
			}
		}
		printf("%d\n",find());
	} 
	return 0;
}
/*
二分图中最小顶点覆盖等于最大匹配数
二分图中最小边覆盖=顶点数-最小顶点覆盖（最大匹配）
二分图中最大独立集+最小顶点覆盖（最大匹配）=顶点数
*/
