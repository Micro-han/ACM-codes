//徐州网赛G. Colorful String
//求字符串s的所有回文子串价值和
//价值被定义为字符串中包含不同字母的数量 
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
    void count(){//主要改cnt 
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
/*以s[i]为结尾的回文串的个数 
t.add(s[0]);printf("%d ",t.num[t.last]);
for(int i = 1;s[i];i++)t.add(s[i]),printf("%d ",t.num[t.last]); 
*/
/*所有回文串中不同字符数量之和 
for(int i = 0;s[i];i++)t.add(s[i]);
t.count();
set<char>st;
dfs(0,st);
dfs(1,st);
printf("%lld\n",ans);
*/
/*所有回文串出现次数*长度 
for(int i=0;s[i];i++)t.add(s[i]);
t.count();
for(int i=t.p;i>=0;i--)ans=max(ans,1ll*t.cnt[i]*t.len[i]);
*/

/*
 int next[MAXN][N] ;//next指针，next指针和字典树类似，指向的串为当前串两端加上同一个字符构成
    int fail[MAXN] ;//fail指针，失配后跳转到fail指针指向的节点
    int cnt[MAXN] ; //表示节点i表示的本质不同的串的个数（建树时求出的不是完全的，最后count()函数跑一遍以后才是正确的）
    int num[MAXN] ; //表示以节点i表示的回文串的最右端点为回文串结尾的回文串个数
    int len[MAXN] ;//len[i]表示节点i表示的回文串的长度（一个节点表示一个回文串）
    int S[MAXN] ;//存放添加的字符
    int last_pos[MAXN];//存放回文串结尾的位置
    //int id[MAXN];//回文子串结尾的地方+1 ,与last_pos功能一样
    int last ;//指向新添加一个字母后所形成的最长回文串表示的节点。
    int n ;//表示添加的字符个数。
    int p ;//表示添加的节点个数。求不同回文串的个数=p-2（要跑count函数）
*/

