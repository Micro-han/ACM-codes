#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const double eps=1e-6;
ll read(){
    ll f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
struct arr{
	double s1,s2,e1,e2;
}a[maxn];
int n,q;
double cross(arr a,double x,double y){
	return (a.s1-x)*(a.e2-y)-(a.e1-x)*(a.s2-y); 
} 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lf%lf%lf%lf",&a[i].s1,&a[i].s2,&a[i].e1,&a[i].e2);
	scanf("%d",&q);
	while(q--){
		double s1,s2,e1,e2;
		int sum=0;
		scanf("%lf%lf%lf%lf",&s1,&s2,&e1,&e2);
		for(int i=1;i<=n;i++)
			if(cross(a[i],s1,s2)*cross(a[i],e1,e2)>eps)continue;
			else sum++;
		if(sum%2)puts("different");
		else puts("same");
	} 
	return 0;
}

