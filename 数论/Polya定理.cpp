#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll n,m,c,ans;
ll quick(ll a,ll b,ll mod){
	ll res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int main(){
	scanf("%lld%lld%lld",&n,&m,&c);
	for(ll i=1;i<=m;i++){
		ans=(ans+quick(c,n*n*__gcd(i,m),mod))%mod;
	}
	ans=(ans*quick(m,mod-2,mod))%mod;
	printf("%lld\n",ans);
	return 0;
}
/*
置换群数量为m
所以每一个为数量为gcd(i,m)
累乘即可
*/