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
bitset<maxn>f[maxn];//f[i][j]==1��ʾi��j��ͨ 
int main(){
	for(int i=1;i<=n;i++)f[i].reset();//��ʼ��
	for(int i=1;i<=n;i++){
		f[i][i]=1;
		for(int j=1;j<=n;j++)
			f[i]|=f[j];//��f[j]��ͨ�ĵ�����f[i]�� 
	} 
	

/*

Ҳ�����������һ��ֱ�ӿ�ʼ�� ��� �� 

b.count();
b����Ϊ1�Ķ�����λ�ĸ���
	
b.size();
b�ж�����λ�ĸ���
	
b[pos];
����b����pos���Ķ�����λ
	
b.test(pos)
b����pos���Ķ�����λ�Ƿ�Ϊ1

b.set()
��b�����ж�����λ����Ϊ1

b.set(pos)
��b����pos���Ķ�����λ��Ϊ1

b.reset()
��b�����ж�����λ����Ϊ0

b.reset(pos)
��b����pos���Ķ�����λ��Ϊ0

b.flip()
��b�����ж�����λ��λȡ��

b.flip(pos)
��b����pos���Ķ�����λȡ��

b.to_ulong()
��b��ͬ���Ķ�����λ����һ��unsigned longֵ
*/
	return 0;
}

