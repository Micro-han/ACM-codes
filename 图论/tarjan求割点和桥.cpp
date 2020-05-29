#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const int N=3e5+10;
const int Maxn=5e5+10;
const double eps=1e-6;
const ll inf=1e18;
ll read(){
    ll f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
int n,m,low[N],dfn[N];
bool is_cut[N];
int father[N];
int anss;
int tim=0;
vector<int>G[N];
void Tarjan(int i,int Father){
    father[i]=Father;/*��¼ÿһ����ĸ���*/
    dfn[i]=low[i]=tim++;
    for(int j=0;j<G[i].size();++j){
        int k=G[i][j];
        if(dfn[k]==-1){
            Tarjan(k,i);
            low[i]=min(low[i],low[k]);
        }
        else if(Father!=k)/*����k��i�ĸ��׵Ļ�����ô�����������е��رߣ����ر���ôһ��������*/
            low[i]=min(low[i],dfn[k]);//dfn[k]���ܣ�=low[k]�����Բ�����low[k]����dfn[k],������Ϸ���ͷ�ˡ�
    }
}
void count(){
    int rootson=0;
    Tarjan(1,0);
    for(int i=2;i<=n;++i){
        int v=father[i];
        if(v==1)
        rootson++;/*ͳ�Ƹ��ڵ������ĸ��������ڵ����������>=2,���Ǹ��*/
        else{
            if(low[i]>=dfn[v])/*��������*/
            is_cut[v]=true;
        }
    }
    if(rootson>1)is_cut[1]=true;
  /*  for(int i=1;i<=n;++i)
    	if(is_cut[i])printf("%d\n",i);*/
	anss=0;
    for(int i=1;i<=n;++i){
        int v=father[i];
        if(v>0&&low[i]>dfn[v]) anss++;/*�ŵ�����*/
      //  printf("%d,%d\n",v,i);
    }
    printf("%d\n",m-anss);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
    memset(dfn,-1,sizeof(dfn));
    memset(father,0,sizeof(father));
    memset(low,-1,sizeof(low));
    memset(is_cut,false,sizeof(is_cut));
    count();
	return 0;
}

