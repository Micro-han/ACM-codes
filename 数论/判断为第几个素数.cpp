#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
LL n;
LL f[3400000],g[3400000],i,j,k;
LL doit(LL n){
    for(k=1;k*k<=n;k++)f[k]=n/k-1;
    for(i=1;i<=k;i++)g[i]=i-1;
    for(i=2;i<=k;i++){
        if(g[i]==g[i-1])continue;
        for(j=1;j<=min(k-1,n/i/i);j++){
            if(i*j<k)f[j]-=f[i*j]-g[i-1];
            else f[j]-=g[n/i/j]-g[i-1];
        }
        for(j=k;j>=i*i;j--)g[j]-=g[j/i]-g[i-1];
    }
    return f[1];
}
int main(){ 
    while(~scanf("%lld",&n)){
        printf("%lld\n",doit(n));
    }
    return 0;
}
 
//∏¥‘”∂» n^(3/4) 
