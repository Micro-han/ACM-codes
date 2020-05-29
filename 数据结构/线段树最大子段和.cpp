#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e4+10;
const int mod=1e9+7;
const ll INF=1e11;
ll read(){
    ll f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
struct arr{
	ll lmx,rmx,sum,num;//lmx前缀 rmx后缀 
}s[maxn*4],nul;
ll a[maxn];
int n;
arr pushup(arr a,arr b){	
	arr t;
	t.sum=a.sum+b.sum;
    t.lmx=max(a.sum+b.lmx,a.lmx);
    t.rmx=max(b.sum+a.rmx,b.rmx);
    t.num=max(a.num,max(b.num,a.rmx+b.lmx));
	return t;
}
void build(int node,int l,int r){
	int mid=(l+r)>>1;
	if(l==r){
		s[node].sum=a[l];
		s[node].lmx=a[l];
		s[node].rmx=a[l];
		s[node].num=a[l];
		return;
	}
	build(node<<1,l,mid);
	build(node<<1|1,mid+1,r);
	s[node]=pushup(s[node<<1],s[node<<1|1]);
}
arr query(int L,int R,int l,int r,int node){
	if(L>R)return nul;
	int mid=(l+r)>>1;
	if(L<=l && r<=R)return s[node];
	if(R<=mid)return query(L,R,l,mid,node<<1);
	if(L>mid)return query(L,R,mid+1,r,node<<1|1);
	return pushup(query(L,R,l,mid,node<<1),query(L,R,mid+1,r,node<<1|1));
}
ll solve(int s1,int e1,int s2,int e2){
	ll ans=0;
	if(e1<s2){
		ans+=query(e1,s2,1,n,1).sum;
		ans+=max(1ll*0,query(s1,e1-1,1,n,1).rmx);
		ans+=max(1ll*0,query(s2+1,e2,1,n,1).lmx);
	}else{
		arr a1=query(s1,s2-1,1,n,1);
		arr a2=query(s2,e1,1,n,1);
		arr a3=query(e1+1,e2,1,n,1);
		ans=max(a2.num,a1.rmx+a2.lmx);
		ans=max(ans,a2.rmx+a3.lmx);
		ans=max(ans,a1.rmx+a2.sum+a3.lmx);
	}
	return ans;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		build(1,1,n);
		int q;
		scanf("%d",&q);
		while(q--){
			int st1,ed1,st2,ed2;
			scanf("%d%d%d%d",&st1,&ed1,&st2,&ed2);
			printf("%lld\n",solve(st1,ed1,st2,ed2));
		}
	}
	return 0;
}
/*
	分两种情况
	1：相交
		按照答案的左右区间所在位置分类讨论
		共四种
		1）答案区间在相交部分 区间和 
		2）左不在右在 左最大后缀+右最大前缀 
		3）左在右不在 同2） 
		4）左右都不在 同2 
	2：不交
		左最大后缀+右最大前缀+左右间的区间和 
	 
*/
