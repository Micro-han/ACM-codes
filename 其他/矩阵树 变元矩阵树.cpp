#include "stdio.h"
#include "string.h"
#include "iostream"
#include "algorithm"
#include "math.h"
#include "queue"
#include "vector"
#include "stack"
#include "set"
#include "map"
#include "unordered_map"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const ll mod=998244353;
const int MOD=998244353;
const ll inf=1e18;
const int maxn=5e5+10;
const ull base=147;
int n,m;
ll gcd(ll a, ll b){
    return b==0?a:gcd(b,a%b);
}
ll a[40][110][110],d[40][110][110];
ll f[40][110][110];
ll gauss(int tt){
    ll ans=1;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<n;j++){
            while(f[tt][j][i]){
                ll t=f[tt][i][i]/f[tt][j][i];
                for(int k=i;k<n;k++)
                    f[tt][i][k]=(f[tt][i][k]-t*f[tt][j][k]%mod+mod)%mod;
                swap(f[tt][i],f[tt][j]);
                ans=-ans;
            }
        }
        ans=(ans*f[tt][i][i])%mod;
    }
    return (ans+mod)%mod;
}
ll quick(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(d,0,sizeof(d));
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            a[0][u][v]++;
            a[0][v][u]++;
            int tot=0;
            while(w){
                int x=w%2;tot++;w/=2;
                if(x==1){
                    a[tot][u][v]++;
                    a[tot][v][u]++;
                }
            }
        }
        /*
        =变元矩阵树
            定义Kirchhoff矩阵𝐾，其中
            𝐾𝑖𝑖为所有与𝑖相连的边的权值和
            𝐾𝑖𝑗为连接𝑖与𝑗的边权值和的负值
            求完全图中最小生成树的权值和
        矩阵树
            𝐾𝑖𝑖 定义为𝑖的度数
            𝐾𝑖𝑗定义为𝑖是否𝑗相连(是则为−1，否则为0)
            求完全图中最小生成树的个数
        */
        for(int i=0;i<32;i++)
            for(int j=1;j<=n;j++)
                for(int k=1;k<=n;k++)
                    d[i][j][j]+=a[i][j][k];
        for(int i=0;i<32;i++)
            for(int j=1;j<=n;j++)
                for(int k=1;k<=n;k++)
                    f[i][j][k]=d[i][j][k]-a[i][j][k];
        ll ds=gauss(0);
        ll ans=0,dd=1;
        for(int i=1;i<32;i++){
            ll t=gauss(i);//答案
            ans=(ans+dd*t)%mod;
            dd=dd*2%mod;
        }
        ll gg=gcd(ans,ds);
        ans/=gg;ds/=gg;
        printf("%lld\n",ans*quick(ds,mod-2)%mod);
    }
    return 0;
}