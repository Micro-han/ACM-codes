#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const int N=2e5+10;
const int Maxn=5e5+10;
const double eps=1e-6;
const ll inf=1e18;
ll read(){
    ll f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
int n,m,a,b;
int s[4000][4000],t[4000][4000];
int f[4000][4000];
int main(){
	scanf("%d%d%d%d",&n,&m,&a,&b);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			int x;
			scanf("%d",&x);
			if(x==1){
				f[i][j]+=1;
				f[i][b-m+j+1]-=1;
				f[a-n+i+1][j]-=1;
				f[a-n+i+1][b-m+j+1]+=1;
			}
		}
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
			t[i][j]=t[i][j-1]+t[i-1][j]-t[i-1][j-1]+f[i][j];
	int sum=0;
	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++)
			sum=max(sum,t[i][j]);
	for(int i=1;i<=a;i++){
		for(int j=1;j<b;j++){
			printf("%d ",int((1.0*t[i][j]/(1.0*sum))*100));
		}
		printf("%d\n",int((1.0*t[i][b]/(1.0*sum))*100));
	}
	return 0;
}
