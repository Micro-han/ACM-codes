#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "iostream"
#include "queue"
using namespace std;
const int maxn=1e5+10;
const int INF=0xfffffff;
struct Edge{
    int to,next,w;
}l[maxn];
struct Node{
    int no,dis;
    friend bool operator < (Node x,Node y){
        return x.dis<y.dis;
    }
}a[maxn];
int n,m,s,x,y,z;
int head[maxn],cnt,cur,dis[maxn];
bool vis[maxn];
priority_queue<Node> q;
void add(int x,int y,int z){
    cnt++;
    l[cnt].to=y,l[cnt].w=z,l[cnt].next=head[x];
    head[x]=cnt;
}
int main(){
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
    }
    for(int i=1;i<=n;i++)a[i].dis=INF,a[i].no=i;
    a[s].dis=0;cur=s;
    q.push(a[s]);
    while(!q.empty()){
        cur=q.top().no;
        q.pop();
        if(vis[cur])continue;
        vis[cur]=1;
        for(int i=head[cur];i;i=l[i].next){
            if(a[l[i].to].dis>a[cur].dis+l[i].w){
                a[l[i].to].dis=a[cur].dis+l[i].w;
                q.push(a[l[i].to]);
            }
        }
    }
    for(int i=1;i<=n;i++)printf("%d:%d\n",i,a[i].dis);
    return 0;
}

