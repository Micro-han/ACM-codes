#include<bits/stdc++.h>
using namespace std;
int n,m;
int sg[1001],a[1001];
void getsg(){    
     bool mex[1001];    
	 for(int i=0;i<=m;i++){        
	     memset(mex,false,sizeof(mex));        		
		 for (int j=1;j<=n;j++){        			
		    if (i-a[j]>=0){
		     	mex[sg[i-a[j]]]=true;
			}
		}        
		for(int j=0;j<=m;j++){
		    if(mex[j]==false){                
			   sg[i]=j;                
			   break;            
			}    
		}
	}
	return;
}//��һ��n��ʯ�� ����ֻ��ȡ��ai�� ��sgn=0��ذ� 
//f[N]:�ɸı䵱ǰ״̬�ķ�ʽ��NΪ��ʽ�����࣬f[N]Ҫ��getSG֮ǰ��Ԥ����
//SG[]:0~n��SG����ֵ
//S[]:Ϊx���״̬�ļ���
int f[N],SG[MAXN],S[MAXN];
void  getSG(int n){
    int i,j;
    memset(SG,0,sizeof(SG));
    //��ΪSG[0]ʼ�յ���0������i��1��ʼ
    for(i = 1; i <= n; i++){
        //ÿһ�ζ�Ҫ����һ״̬ �� ��̼��� ����
        memset(S,0,sizeof(S));
        for(j = 0; f[j] <= i && j <= N; j++)
            S[SG[i-f[j]]] = 1;  //�����״̬��SG����ֵ���б��
        for(j = 0;; j++) if(!S[j]){   //��ѯ��ǰ���״̬SGֵ����С�ķ���ֵ
            SG[i] = j;
            break;
        }
    }
}


//ע�� S����Ҫ����С�������� SG����Ҫ��ʼ��Ϊ-1 ����ÿ������ֻ���ʼ��1��
//n�Ǽ���s�Ĵ�С S[i]�Ƕ��������ȡ�����������
int s[110],sg[10010],n;
int SG_dfs(int x)
{
    int i;
    if(sg[x]!=-1)
        return sg[x];
    bool vis[110];
    memset(vis,0,sizeof(vis));
    for(i=0;i<n;i++)
    {
        if(x>=s[i])
        {
            SG_dfs(x-s[i]);
            vis[sg[x-s[i]]]=1;
        }
    }
    int e;
    for(i=0;;i++)
        if(!vis[i])
        {
            e=i;
            break;
        }
    return sg[x]=e;
}
