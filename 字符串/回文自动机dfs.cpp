//��������G. Colorful String
//���ַ���s�����л����Ӵ���ֵ��
//��ֵ������Ϊ�ַ����а�����ͬ��ĸ������ 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
static const int maxn = 300010;
static const int INF = 0x3f3f3f3f;
static const int mod = (int)1e9 + 7;
static const double eps = 1e-6;
static const double pi = acos(-1);
static const int N = 26;

ll ans;
char s[maxn];
struct Palindromic_Tree {
    int next[maxn][N],fail[maxn],cnt[maxn],num[maxn],len[maxn],S[maxn],last,n,p;
    int id[maxn]; 
	int newnode(int l){
        for(int i = 0;i < N;i++)next[p][i] = 0 ;
        cnt[p] = num[p] = 0;
        len[p] = l;
        return p++;
    }
    void init(){
        p = 0;
        newnode(0);
        newnode(-1);
        last = 0;
        n = 0;
        S[n] = -1;
        fail[0] = 1;
    }
    int get_fail(int x){
        while(S[n - len[x] - 1] != S[n])x = fail[x];
        return x;
    }
    void add(int c){
        c -= 'a';
        S[++n] = c;
        int cur = get_fail(last);
        if(!next[cur][c]){
            int now = newnode(len[cur] + 2);
            fail[now] = next[get_fail(fail[cur])][c];
            next[cur][c] = now;
            num[now] = num[fail[now]] + 1;
        }
        last = next[cur][c];
        cnt[last]++;id[last]=n;
    }
    void count(){//��Ҫ��cnt 
        for(int i = p - 1;i >= 0;i--)cnt[fail[i]] += cnt[i];
    }
}t;

void dfs(int u,set<char>&s){
    for(int i = 0;i < N;i++){
        int x = t.next[u][i];
        if(x){
            set<char>v;
            v = s;
            v.insert(i);
            ans += t.cnt[x]*v.size();
            dfs(x,v);
        }
    }
}

int main() {
    t.init();
    scanf("%s",s);
    for(int i = 0;s[i];i++)t.add(s[i]);
    t.count();
    set<char>st;
    dfs(0,st);
    dfs(1,st);
    printf("%lld\n",ans);
    return 0;
}
/*��s[i]Ϊ��β�Ļ��Ĵ��ĸ��� 
t.add(s[0]);printf("%d ",t.num[t.last]);
for(int i = 1;s[i];i++)t.add(s[i]),printf("%d ",t.num[t.last]); 
*/
/*���л��Ĵ��в�ͬ�ַ�����֮�� 
for(int i = 0;s[i];i++)t.add(s[i]);
t.count();
set<char>st;
dfs(0,st);
dfs(1,st);
printf("%lld\n",ans);
*/
/*���л��Ĵ����ִ���*���� 
for(int i=0;s[i];i++)t.add(s[i]);
t.count();
for(int i=t.p;i>=0;i--)ans=max(ans,1ll*t.cnt[i]*t.len[i]);
*/

/*
 int next[MAXN][N] ;//nextָ�룬nextָ����ֵ������ƣ�ָ��Ĵ�Ϊ��ǰ�����˼���ͬһ���ַ�����
    int fail[MAXN] ;//failָ�룬ʧ�����ת��failָ��ָ��Ľڵ�
    int cnt[MAXN] ; //��ʾ�ڵ�i��ʾ�ı��ʲ�ͬ�Ĵ��ĸ���������ʱ����Ĳ�����ȫ�ģ����count()������һ���Ժ������ȷ�ģ�
    int num[MAXN] ; //��ʾ�Խڵ�i��ʾ�Ļ��Ĵ������Ҷ˵�Ϊ���Ĵ���β�Ļ��Ĵ�����
    int len[MAXN] ;//len[i]��ʾ�ڵ�i��ʾ�Ļ��Ĵ��ĳ��ȣ�һ���ڵ��ʾһ�����Ĵ���
    int S[MAXN] ;//�����ӵ��ַ�
    int last_pos[MAXN];//��Ż��Ĵ���β��λ��
    //int id[MAXN];//�����Ӵ���β�ĵط�+1 ,��last_pos����һ��
    int last ;//ָ�������һ����ĸ�����γɵ�����Ĵ���ʾ�Ľڵ㡣
    int n ;//��ʾ��ӵ��ַ�������
    int p ;//��ʾ��ӵĽڵ��������ͬ���Ĵ��ĸ���=p-2��Ҫ��count������
*/

