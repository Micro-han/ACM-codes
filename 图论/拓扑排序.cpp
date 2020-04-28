#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e4+10;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
inline int read(){
    int f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
int n,m,cnt,num,ans;
bitset<maxn>f[maxn];
struct arr{
	int next,to;
}edge[50010];
int head[maxn],in[maxn],a[maxn],b[maxn],to[maxn];
inline bool cmp(int x,int y){
	return b[x]<b[y];
}
inline void add(int x,int y){
	cnt++;
	edge[cnt].to=y;edge[cnt].next=head[x];
	head[x]=cnt;
}//存图 
inline void topusort(){
	queue<int>q;
	for(int i=1;i<=n;i++)
		if(!in[i])q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		a[++num]=x;//第几个入队的是谁 
		b[x]=num;//谁第几个入队 
		for(int i=head[x];i!=-1;i=edge[i].next){
			in[edge[i].to]--;
			if(!in[edge[i].to])q.push(edge[i].to);
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		memset(head,-1,sizeof(head));
		cnt=0;num=0;ans=0;
		n=read();m=read();
		for(int i=1;i<=n;i++)f[i].reset();
		for(int i=1;i<=m;i++){
			int x,y;
			x=read();y=read();
			add(x,y);
			in[y]++;
		}
		topusort();
		printf("%d\n",ans);
	}
	return 0;
}

