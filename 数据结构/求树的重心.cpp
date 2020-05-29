#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
ll read(){
    ll f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
int n,ans,size=INF;
vector<int>G[maxn];
int son[maxn],vis[maxn];
void dfs(int cur){
	vis[cur]=1;
	son[cur]=0;
	int tmp=0;
	for(int i=0;i<G[cur].size();i++){
		int u=G[cur][i];
		if(!vis[u]){
			dfs(u);
			son[cur]+=son[u]+1;
			tmp=max(tmp,son[u]+1); 
		}
	}
	tmp=max(tmp,n-son[cur]-1);
	if(tmp<size || tmp==size && cur<ans){
		ans=cur;
		size=tmp;
	}
}
ll sum=0;
void dfs2(int x,int fa,int dep){
	for(int i=0;i<G[x].size();i++){
		int u=G[x][i];
		if(u==fa)continue;
		dfs2(u,x,dep+1);
	}
	sum=sum+1ll*dep;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1); 
	dfs2(ans,-1,0);
	printf("%lld\n",sum);
	return 0;
}

