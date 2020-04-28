#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=500*250+10;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
ll read(){
    ll f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
struct arr{
	int x,y,c;
}a[maxn];
int f[maxn],rk[maxn];
int n,m;
bool cmp(arr a,arr b){
	if(a.c==b.c)return a.x<b.x;
	return a.c<b.c;
}
int find(int x){
	if(x!=f[x])return f[x]=find(f[x]);
	return f[x];
}
void unite(int x,int y){
    int a=find(x),b=find(y);
    if(a!=b)f[b]=a;
}
int k(int n,int m){
	int ans=0,tot=0;
    for(int i=1;i<=n;i++){
    	int fa=find(a[i].x),fb=find(a[i].y);
	   	if(fa!=fb){
	        unite(a[i].x,a[i].y);
	        ans+=a[i].c;
	        tot++;
	    }
	    if(tot==m-1)break;
    }
    return ans;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].c);
		sort(a+1,a+1+m,cmp);
		for(int i=0;i<n;i++)f[i]=i,rk[i]=0;
		printf("%d\n",k(m,n));
	} 
	return 0;
}

