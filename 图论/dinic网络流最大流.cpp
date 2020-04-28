#include "stdio.h"
#include "string.h"
#include "iostream"
#include "algorithm"
#include "math.h"
#include "queue"
using namespace std;
typedef long long LL;
const int maxn=1e6+10;
const int INF=0x3f3f3f;
int n,m,S,T,x,y,z,cnt;
int head[maxn],Rank[maxn];
queue<int>q;
struct arr{
    int from,to,cost,next;
}edge[maxn];
void add(int x,int y,int z){
    cnt++;
    edge[cnt].from=x;edge[cnt].to=y;edge[cnt].cost=z;edge[cnt].next=head[x];head[x]=cnt;
}
bool bfs(){
    memset(Rank,-1,sizeof(Rank));
    Rank[S]=0;q.push(S);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].to;
            if(edge[i].cost && Rank[v]==-1){
                Rank[v]=Rank[u]+1;
                q.push(v);
            }
        }
    }
    if(Rank[T]!=-1)return true;
    return false;
}
int dfs(int u,int flow){
    if(u==T)return flow;
    int ret=flow;
    for(int i=head[u];i!=-1;i=edge[i].next){
        if(ret<=0)break;
        int v=edge[i].to;
        if(edge[i].cost && Rank[u]+1==Rank[v]){
            int k=dfs(v,min(edge[i].cost,ret));
            ret-=k;edge[i].cost-=k;edge[i^1].cost+=k;
        }
    }
    return flow-ret;
}
int dinic(){
    int ans=0;
    while(bfs())ans+=dfs(S,INF);
    return ans;
}
int main(){
    cnt=1;
    memset(head,-1,sizeof(head));
    scanf("%d%d%d%d",&n,&m,&S,&T);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);add(y,x,0);
    }
    printf("%d\n",dinic());
    return 0;
}
