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
ll m[maxn],r[maxn];
int n;
void exgcd(ll a,ll b,ll &d,ll &x,ll &y){
	if(!b)d=a,x=1,y=0;
	else {
		exgcd(b,a%b,d,y,x);
		y-=x*(a/b);
	}
}
ll exchina(int n){
	ll M=m[1],R=r[1],x,y,d;
	for(int i=2;i<=n;i++){
		exgcd(M,m[i],d,x,y);
		if((r[i]-R)%d)return -1;
		x=(r[i]-R)/d*x%(m[i]/d);
		R+=x*M;
		M=M/d*m[i];
		R%=M;
	}
	if(R>0)return R;
	return R+M;
}
int main(){
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++)scanf("%lld%lld",&m[i],&r[i]);
		printf("%lld\n",exchina(n));
	}
	return 0;
}

