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
struct BigN{
	int c,s[maxn];
	char a[maxn];
	int len;
	BigN(){}
	void operator =(int x){
		c=0;len=0;
		memset(s,0,sizeof(s));
		while(x)s[c++]=x%10,x/=10;
		for(int i=c;i>0;i--)a[len++]=s[i]+'0';
	}
	void put(){
		for(int i=1;i<50 && i<=c;i++)printf("%d",s[c-i]);
		printf("\n");
	}
}num[3];
void add(const BigN& a,const BigN& b,BigN& ans){
	int tmp=0;
	ans.c=max(a.c,b.c);
	for(int i=max(min(a.c,b.c)-50,0);i<a.c || i<b.c;i++){
		if(i<a.c)tmp+=a.s[i];
		if(i<b.c)tmp+=b.s[i];
		ans.s[i]=tmp%10;
		tmp/=10;
	}
	while(tmp){
		ans.s[ans.c++]=tmp%10;
		tmp/=10;
	}
	ans.len=0;
	for(int i=ans.c-1;i>=0;i--)ans.a[ans.len++]=ans.s[i]+'0';
}
string add(string a,string b){
	v.clear();
	int tmp=0,t=0;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	while(a.size()!=b.size()){
		if(a.size()>b.size())b.push_back('0');
		else a.push_back('0');
	}
	for(int i=0;i<a.size();i++){
		tmp=a[i]+b[i]-'0'*2+t;
		t=tmp/10;
		v.push_back(tmp%10+'0');
	}
	if(t>0)v.push_back(t+'0');
	reverse(v.begin(),v.end());
	return v;
}
int main(){
	return 0;
}
/*
无限循环小数转换成分数 就是将循环节比上999999
*/ 

