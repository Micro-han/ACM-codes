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
int n,a[510],dp[510][510],f[510][510];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		dp[i][i]=1,f[i][i]=a[i];
	for(int len=2;len<=n;len++){
		for(int i=1;i<=n-len+1;i++){
			int j=i+len-1;
			dp[i][j]=INF;
			for(int k=i;k<=j-1;k++){
				if(dp[i][j]>=dp[i][k]+dp[k+1][j]){
					dp[i][j]=dp[i][k]+dp[k+1][j];
					if(dp[i][k]==1 && dp[k+1][j]==1 && f[i][k]==f[k+1][j]){
						dp[i][j]=1;
						f[i][j]=f[i][k]+1;
					} 
				}
			} 
		}
	} 
	printf("%d\n",dp[1][n]);
	return 0;
}
/*

 for(int i=1;i<=n;i++) dp[i][i]=0,s[i][i]=i;
     for(int r=1;r<n;r++){
         for(int i=1;i<n;i++){
             int j=i+r;
             if(j>n) break;
             dp[i][j]=INF;
             for(int k=s[i][j-1];k<=s[i+1][j];k++){
                 if(dp[i][j]>dp[i][k]+dp[k+1][j]){
                     dp[i][j]=dp[i][k]+dp[k+1][j];
                     s[i][j]=k;
                 }
             }
             dp[i][j]+=sum[j]-sum[i-1];
         }
     }
区间dp四边形优化 
*/
