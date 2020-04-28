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
struct arr{
	ll dis,to;
}ar;
vector<arr>G[maxn];
ll d[maxn],vis[maxn];
int n,m,s;
void spfa(int s) {
    queue<int> que;
    for(int i=1;i<=n;i++) d[i] = 1e18;
    d[s] = 0;
    que.push(s);
    while(!que.empty()) {
        int v = que.front();que.pop();
        vis[v] = 0;
        for(int i=0;i<G[v].size();i++) {
            int u = G[v][i].to;
            if(vis[u]) continue;
            if(d[v] != 1e18 && d[u] > d[v] + G[v][i].dis) {
                d[u] = d[v] + G[v][i].dis;
                que.push(u);
                vis[u] = 1;
            }
        }
    }
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	for(int i=0;i<m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		ar.dis=w;ar.to=v;
		G[u].push_back(ar);
		ar.dis=w;ar.to=u;
		G[v].push_back(ar);
	}
	return 0;
}

