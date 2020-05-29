#include "stdio.h"
#include "string.h"
#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;
const int maxn=1e4+10;
vector<int>G[maxn];
int n,cnt;
int head[maxn],d[maxn],in[maxn],f[maxn][31];//f[x][y]表示x向上i跳2^y步的祖先节点
void dfs(int pos,int fa){
    d[pos]=d[fa]+1;//d代表深度
    f[pos][0]=fa;
    for(int i=0;i<=19;i++)
        f[pos][i+1]=f[f[pos][i]][i];
    for(int i=0;i<G[pos].size();i++){
        int u=G[pos][i];
        if(u==fa)continue;
        //dis[u]=dis[pos]+edge[i].v; 
        f[u][0]=pos;
        dfs(u,pos);
    }
}//dfs预处理f数组
int LCA(int x,int y){
    if(d[x]<d[y])swap(x,y);
    for(int i=20;i>=0;i--){
        if(d[f[x][i]]>=d[y])x=f[x][i];
        if(x==y)return x;
    }//保持x和y在同一深度
    for(int i=20;i>=0;i--)
        if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
    return f[x][0];
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(in,0,sizeof(in));
        memset(f,0,sizeof(f));
        memset(d,0,sizeof(d));d[0]=-1;
        for(int i=1;i<=n;i++)G[i].clear();
        for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            G[x].push_back(y);
            f[y][0]=x; in[y]++;
        }
        int node;
        for(int i=1;i<=n;i++)
        	if(!in[i]){
        		node=i;
        		break;
			}
        dfs(node,0);
        int u,v;
        scanf("%d%d",&u,&v);
        printf("%d\n",LCA(u,v));
    }
    return 0;
}

