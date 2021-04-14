#include<bits/stdc++.h>
#define N 1100000
#define M 5500000
#define db double
#define ll long long 
#define ldb long double
#define ull unsigned long long
using namespace std;
const int h=3,ki=149,mo=1e9+7;
int mod(int x){return (x%mo+mo)%mo;}
int inc(int x,int k){x+=k;return x<mo?x:x-mo;}
int dec(int x,int k){x-=k;return x>=0?x:x+mo;}
int read(){int x;scanf("%d",&x);return x;}
void write(int x){printf("%d",x);}
struct node{int x,y,z;};
node operator+(node f,node g){return (node){inc(f.x,g.x),inc(f.y,g.y),inc(f.z,g.z)};}
node operator*(node f,int k){return {1ll*f.x*k%mo,1ll*f.y*k%mo,1ll*f.z*k%mo};}
node sp(node f,int k)
{
    k%=3;
    if(k==0)return (node){f.x,f.y,f.z};
    if(k==1)return (node){f.y,f.z,f.x};
    if(k==2)return (node){f.z,f.x,f.y};
}
struct Segment_Tree
{
    #define lson lc[o]
    #define rson rc[o]
    #define mid ((l+r)>>1)
    node f[M],addv[M];
    int size=0,lc[M],rc[M],mulv[M],revv[M];
    void insert(int &o){if(!o)o=++size,mulv[o]=1;}
    int pushup(int o){f[o]=f[lson]+f[rson];}
    void mul(int o,int k)
    {
        f[o]=f[o]*k;
        addv[o]=addv[o]*k;
        mulv[o]=1ll*mulv[o]*k%mo;
    }
    void rev(int o,int k)
    {
        f[o]=sp(f[o],k);
        addv[o]=sp(addv[o],k);
        revv[o]=(revv[o]+k)%3;
    }
    void add(int o,int l,int r,node k)
    {
        f[o]=f[o]+(k*(r-l+1));
        addv[o]=addv[o]+k;
    }
    void pushdown(int o,int l,int r)
    {
        insert(lson);mul(lson,mulv[o]);rev(lson,revv[o]);add(lson,l,mid,addv[o]);
        insert(rson);mul(rson,mulv[o]);rev(rson,revv[o]);add(rson,mid+1,r,addv[o]);
        mulv[o]=1;revv[o]=0;addv[o]=(node){0,0,0};
    }
    void optmul(int &o,int l,int r,int ql,int qr,int k)
    {
        insert(o);
        if(ql<=l&&r<=qr)return mul(o,k);
        pushdown(o,l,r);
        if(ql<=mid)optmul(lson,l,mid,ql,qr,k);
        if(qr>mid)optmul(rson,mid+1,r,ql,qr,k);
        pushup(o);
    }
    void optrev(int &o,int l,int r,int ql,int qr,int k)
    {
        insert(o);
        if(ql<=l&&r<=qr)return rev(o,k);
        pushdown(o,l,r);
        if(ql<=mid)optrev(lson,l,mid,ql,qr,k);
        if(qr>mid)optrev(rson,mid+1,r,ql,qr,k);
        pushup(o);
    }   
    void optadd(int &o,int l,int r,int ql,int qr,node k)
    {
        insert(o);
        if(ql<=l&&r<=qr)return add(o,l,r,k);
        pushdown(o,l,r);
        if(ql<=mid)optadd(lson,l,mid,ql,qr,k);
        if(qr>mid)optadd(rson,mid+1,r,ql,qr,k);
        pushup(o);
    }
    node query(int o,int l,int r,int ql,int qr)
    {
        if(!o)return (node){0,0,0};
        if(ql<=l&&r<=qr)return f[o];
        pushdown(o,l,r);
        node ans=(node){0,0,0};
        if(ql<=mid)ans=ans+query(lson,l,mid,ql,qr);
        if(qr>mid)ans=ans+query(rson,mid+1,r,ql,qr);
        return ans;
    }
}T;
int main()
{
    int n=read(),qnum=read(),rt=0;
    for(int i=1;i<=qnum;i++)
    {
        int flag=read(),l=read(),r=read();
        if(flag==1)
        {
            node k;
            k.x=read();k.y=read();k.z=read();
            T.optadd(rt,1,n,l,r,k);
        }
        if(flag==2)
        {
            int k;
            k=read();
            T.optmul(rt,1,n,l,r,k);
        }
        if(flag==3)
        {
            T.optrev(rt,1,n,l,r,1);
        }
        if(flag==4)
        {
            node ans=T.query(rt,1,n,l,r);
            int res=0;
            res=inc(res,1ll*ans.x*ans.x%mo);
            res=inc(res,1ll*ans.y*ans.y%mo);
            res=inc(res,1ll*ans.z*ans.z%mo);
            printf("%d\n",res);
        }
    }
    return 0;
}