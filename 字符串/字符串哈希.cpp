#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1e5+10;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
ll read(){
    ll f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
ull h1[maxn],h2[maxn];
char s[maxn];
void gethash(int len){
	h1[0]=1;h2[0]=1;
	for(int i=1;i<=len;i++)
		h1[i]=h1[i-1]*131+(s[i-1]-'a'),h2[i]=h2[i-1]*131;
}
ull usehash(int l,int r){
	return h1[r]-h1[l-1]*h2[r-l+1];
}
int main(){
	scanf("%s",&s);
	gethash(strlen(s)); 
	return 0;
}

