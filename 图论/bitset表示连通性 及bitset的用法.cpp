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
bitset<maxn>f[maxn];//f[i][j]==1表示i和j连通 
int main(){
	for(int i=1;i<=n;i++)f[i].reset();//初始化
	for(int i=1;i<=n;i++){
		f[i][i]=1;
		for(int j=1;j<=n;j++)
			f[i]|=f[j];//将f[j]连通的点连到f[i]上 
	} 
	

/*

也可像二进制数一样直接开始或 异或 与 

b.count();
b中置为1的二进制位的个数
	
b.size();
b中二进制位的个数
	
b[pos];
访问b中在pos处的二进制位
	
b.test(pos)
b中在pos处的二进制位是否为1

b.set()
把b中所有二进制位都置为1

b.set(pos)
把b中在pos处的二进制位置为1

b.reset()
把b中所有二进制位都置为0

b.reset(pos)
把b中在pos处的二进制位置为0

b.flip()
把b中所有二进制位逐位取反

b.flip(pos)
把b中在pos处的二进制位取反

b.to_ulong()
用b中同样的二进制位返回一个unsigned long值
*/
	return 0;
}

