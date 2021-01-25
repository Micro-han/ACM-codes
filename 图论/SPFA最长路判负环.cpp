#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n,m;
vector<pair<int,double> >G[N];
int vis[N],cnt[N];
double dis[N];
queue<int>q;

bool SPFA(int s){
	while(!q.empty())q.pop();
	memset(vis,0,sizeof(vis));
	memset(dis,-127,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	dis[s] = 0; q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		vis[u]=0;
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i].first;
			double d=G[u][i].second;
			if(dis[v]<dis[u]+d){
				dis[v]=dis[u]+d;
				if(!vis[v]){
					cnt[v]++;
					vis[v]=1;
					q.push(v);
				}
			}
			if(cnt[v]>=n)return true;
		}		
	}
	return false;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;double z;
		scanf("%d%d%lf",&x,&y,&z);
		G[x].push_back(make_pair(y,log(z)));
	}
	int flag=0;
	for(int i=1;i<=n;i++){
		flag=SPFA(i);
		if(flag)break;	
	}
	if(flag)puts("inadmissible");
	else puts("admissible");
	return 0;
}
