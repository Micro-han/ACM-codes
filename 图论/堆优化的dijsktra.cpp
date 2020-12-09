#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <time.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int N = 5e2 +10;
const ll mod = 998244353;
const ll inf = 1e18;
const double eps = 1e-8;
const int maxn = 2e5+10;
const int INF = 1e6;
const double mpi=3.1415926535;
inline int read() {
    int f=1,x=0;char ch;
    do {ch=getchar(); if(ch=='-') f=-1;} while (ch<'0'||ch>'9');
    do {x=x*10+ch-'0'; ch=getchar(); } while (ch>='0'&&ch<='9');
    return x*f;
}

struct Edge{
    int to,next,w;
}l[maxn];
struct Node{
    int no;
    ll dis;
    friend bool operator < (Node x,Node y){
        return x.dis>y.dis;
    }
}a[maxn];
int n,m,s,x,y,z;
int head[maxn],cnt,cur,dis[maxn];
bool vis[maxn];
int f[maxn],fcnt;
int path[maxn];
priority_queue<Node> q;
void add(int x,int y,int z){
    cnt++;
    l[cnt].to=y,l[cnt].w=z,l[cnt].next=head[x];
    head[x]=cnt;
}
int main(){
    scanf("%d%d",&n,&m);
    s=1;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
    }
    for(int i=1;i<=n;i++)a[i].dis=inf,a[i].no=i,path[i]=-1;
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
                path[l[i].to]=cur;
                q.push(a[l[i].to]);
            }
        }
    }
    if(a[n].dis==inf)puts("-1");
    else{
        int pos=n;
        while(path[pos]!=-1)f[++fcnt]=pos,pos=path[pos];
        f[++fcnt]=1;
        reverse(f+1,f+1+fcnt);
        for(int i=1;i<fcnt;i++)printf("%d ",f[i]);printf("%d\n",f[fcnt]);
    }
    //for(int i=1;i<=n;i++)printf("%d:%d\n",i,a[i].dis);
    return 0;
}
