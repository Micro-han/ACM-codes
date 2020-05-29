#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
struct arr{
    long long a[2][2];
}ans,shu,mp,bz;
int T;
long long n,a,b,c,p;
long long quick(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1)ans=ans*a%p;
        a=a*a%p;
        b>>=1;
    }
    return ans;
}
arr matrix(arr x,arr y){
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++){
            mp.a[i][j]=0;
            for(int k=0;k<2;k++)
                mp.a[i][j]=(mp.a[i][j]+x.a[i][k]*y.a[k][j])%(p);
        }
    return mp;
}
long long work(long long k){
    ans={1,0,0,1};
    while(k){
        if(k&1)ans=matrix(ans,shu);
        k>>=1;
        shu=matrix(shu,shu);
    }
    return (ans.a[0][1]+ans.a[1][1])%7;
}
int main(){
    p=7;
    while(~scanf("%d%d%d",&a,&b,&c) && a && b && c){
        if(c==1)printf("1\n");
        if(c==2)printf("1\n");
        if(c>=3){
            shu={a,1,b,0};
            printf("%lld\n",work(c-1));
        }
    }
    return 0;
}

