#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
struct arr{
	int sum[4],lazy[4];
}tr[maxn];
int n,m,a[maxn];
void pushup(int node,int i){
	tr[node].sum[i]=tr[node<<1].sum[i]+tr[node<<1|1].sum[i];
}
void pushdown(int node,int mid,int i){
	if(!tr[node].lazy[i]){//如果进行了AND操作，并且该位为0 清空下面子树。
		tr[node<<1].lazy[i]=0;
		tr[node<<1|1].lazy[i]=0;
		tr[node<<1].sum[i]=tr[node<<1|1].sum[i]=0;
	}
	if(tr[node].lazy[i]==1){ //如果进行了OR 操作，并且该位为1 填满下面子树。
		tr[node<<1].lazy[i]=1;
		tr[node<<1|1].lazy[i]=1;
		tr[node<<1].sum[i]=mid-(mid>>1);
		tr[node<<1|1].sum[i]=mid>>1;
	}
	if(tr[node].lazy[i]==2){   //如果进行了XOR操作
		if(tr[node<<1].lazy[i]==INF){//如果没有进行过任何操作，标记为XOR操作
			tr[node<<1].lazy[i]=2;
			tr[node<<1].sum[i]=mid-(mid>>1)-tr[node<<1].sum[i];
		}else if(tr[node<<1].lazy[i]==2){ //如果进行过XOR操作，a^b^b==a 恢复操作内容。
			tr[node<<1].lazy[i]=INF;
			tr[node<<1].sum[i]=mid-(mid>>1)-tr[node<<1].sum[i];
		}else{
			tr[node<<1].lazy[i]^=1;
			if(!tr[node<<1].lazy[i])tr[node<<1].sum[i]=0;
			else tr[node<<1].sum[i]=mid-(mid>>1);
		}
		//另一颗子树同理
		if(tr[node<<1|1].lazy[i]==INF){
			tr[node<<1|1].lazy[i]=2;
			tr[node<<1|1].sum[i]=(mid>>1)-tr[node<<1|1].sum[i];
		}else if(tr[node<<1|1].lazy[i]==2){
			tr[node<<1|1].lazy[i]=INF;
			tr[node<<1|1].sum[i]=(mid>>1)-tr[node<<1|1].sum[i];
		}else{
			tr[node<<1|1].lazy[i]^=1;
			if(!tr[node<<1|1].lazy[i])tr[node<<1|1].sum[i]=0;
			else tr[node<<1|1].sum[i]=mid>>1;
		}
	}
	tr[node].lazy[i]=INF;
}
void build(int l,int r,int node){
	for(int i=0;i<4;i++)tr[node].lazy[i]=INF;
	if(l==r){
		for(int i=0;i<4;i++)tr[node].sum[i]=(bool)(a[l]&(1<<i));
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,node<<1);
	build(mid+1,r,node<<1|1);
	for(int i=0;i<4;i++)pushup(node,i);
}
void update(int L,int R,int v,int i,int l,int r,int node){
	if(r<=R &&L<=l){
		if(v==0)tr[node].sum[i]=0,tr[node].lazy[i]=v;
		if(v==1)tr[node].sum[i]=r-l+1,tr[node].lazy[i]=v;
		if(v==2){
			tr[node].sum[i]=r-l+1-tr[node].sum[i];
			if(tr[node].lazy[i]==2)tr[node].lazy[i]=INF;
			else if(tr[node].lazy[i]==INF)tr[node].lazy[i]=2;
			else tr[node].lazy[i]^=1;
		}
		return;
	}
	pushdown(node,r-l+1,i);
	int mid=(r+l)>>1;
	if(L<=mid)update(L,R,v,i,l,mid,node<<1);
	if(R>mid)update(L,R,v,i,mid+1,r,node<<1|1);
	pushup(node,i);
}
int query(int L,int R,int i,int l,int r,int node){
	if(L<=l && r<=R)return tr[node].sum[i];
	int mid=(l+r)>>1,ans=0;
	pushdown(node,r-l+1,i);
	if(L<=mid)ans+=query(L,R,i,l,mid,node<<1);
	if(R>mid)ans+=query(L,R,i,mid+1,r,node<<1|1);
	return ans;
}
ll read(){
    ll f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		build(1,n,1);
		while(m--){
			char opt[5];
			scanf("%s",&opt);
			if(opt[0]=='S'){
				int l,r,sum=0;
				scanf("%d%d",&l,&r);
				l++,r++;
				for(int i=0;i<4;i++)
					sum+=query(l,r,i,1,n,1)<<i;
				printf("%d\n",sum);
			}else{
				int x,l,r;
				scanf("%d%d%d",&x,&l,&r);
				l++,r++;
				if(opt[0]=='A'){
					for(int i=0;i<4;i++){
						int num=x&(1<<i);
						if(!num)update(l,r,0,i,1,n,1);
					}
				}
				if(opt[0]=='O'){
					for(int i=0;i<4;i++){
						int num=x&(1<<i);
						if(num)update(l,r,1,i,1,n,1);
					}
				}
				if(opt[0]=='X'){
					for(int i=0;i<4;i++){
						int num=x&(1<<i);
						if(num)update(l,r,2,i,1,n,1);
					}
				}
			}
		}
	}
	return 0;
}

