#include<bits/stdc++.h>
using namespace std;
long long n,ans;
int main()
{
    // \sum{i=1,n}n/i;
  scanf("%lld",&n);
  for(int l=1,r;l<=n;l=r+1)
     {
        r=n/(n/l);
        ans+=(r-l+1)*(n/l);
        cout<<l<<' '<<r<<' '<<ans<<endl;
     }
  printf("%lld",ans);
}
