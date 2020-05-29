typedef long long LL;
const int MAXN = 200010;
const LL mod = 223092870;
struct Node{
    LL d, first, sum;
}t[MAXN<<2];
LL a[MAXN];
int n, m;
 
inline void pd(int i,int l,int r) {
    if (t[i].d || t[i].first) {
        int mid = (l + r) >> 1;
        (t[i<<1].d += t[i].d) %= mod;
        (t[i<<1|1].d += t[i].d) %= mod;
        (t[i<<1].first += t[i].first) %= mod;
        (t[i<<1|1].first += (t[i].first+(mid-l+1)*t[i].d%mod)) %= mod;
        (t[i<<1].sum += t[i].first*(mid-l+1)%mod+(1ll*(mid-l+1)*(mid-l)/2)%mod*t[i].d%mod) %= mod;
        (t[i<<1|1].sum += (t[i].first+(mid-l+1)*t[i].d)%mod*(r-mid)%mod+(1ll*(r-mid)*(r-mid-1)/2)%mod*t[i].d%mod) %= mod;
        t[i].d = t[i].first = 0;
    }
}
 
void ins(int i, int l, int r, int x, int y, int first, int d) {
    if (x <= l && r <= y){
        (t[i].d += d) %= mod;
        (t[i].first += 1ll*(l-x)*d%mod+first) %= mod;
        (t[i].sum += (1ll*(l-x)*d%mod+first)%mod*(r-l+1)%mod + (1ll*(r-l+1)*(r-l)/2)%mod*d%mod) %= mod;
        return;
    }
    pd(i, l, r);
    int mid = (l + r) >> 1;
    if (x <= mid) ins(i<<1,l,mid,x,y,first,d);
    if (y > mid) ins(i<<1|1,mid+1,r,x,y,first,d);
    t[i].sum = (t[i<<1].sum + t[i<<1|1].sum) % mod;
}
 
LL query(int i,int l,int r,int x, int y) {
    if(x <= l && r <= y) return t[i].sum;
    pd(i,l,r);
    int mid = (l+r) >> 1; LL re = 0;
    if (x <= mid)  re += query(i<<1,l,mid,x,y);
    if (y > mid) re += query(i<<1|1,mid+1,r,x,y);
    return re;
}
 
int main()
{  
    read(n);
    for (int i=1;i<=n;i++) read(a[i]), (a[i] += a[i-1]) %= mod;
    read(m);
    int op, l, r, v, d;
    while(m--) {
        read(op);
        if(op == 1) {
            read(l), read(r), read(v), read(d);
            ins(1, 1, n, l, r, v, d);
        }
        else {
            read(l), read(r), read(v);
            printf("%lld\n", ((query(1,1,n,l,r)+a[r]-a[l-1])%v+v)%v);
        }
    }
}
