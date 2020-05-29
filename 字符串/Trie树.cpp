//对于字符串比较多的要统计个数的，map被卡的情况下，直接用字典树
//很多题都是要用到节点下标来表示某个字符串
const int maxn =2e6+5;//如果是64MB可以开到2e6+5，尽量开大
int tree[maxn][30];//tree[i][j]表示节点i的第j个儿子的节点编号
bool flagg[maxn];//表示以该节点结尾是一个单词
int tot;//总节点数
int sum[maxn];//sum[rt]表示当前字符串结尾节点的访问次数 
void insert(char *s){
	int len=strlen(s);
	int rt=0;
	for(int i=0;i<len;i++){
		int id=s[i]-'a';
		if(!tree[rt][id])tree[rt][id]=++tot;
		sum[tree[rt][id]]++;
		rt=tree[rt][id]; 
	}
	flagg[rt]=1;
}
int find(char *s){
	int len=strlen(s);
	int rt=0;
	for(int i=0;i<len;i++){
		int id=s[i]-'a';
		if(!tree[rt][id])return 0;
		rt=tree[rt][id];
	}
	return sum[rt];
}
void init()//最后清空，节省时间
{
    for(int i=0;i<=tot;i++)
    {
       flagg[i]=false;
       for(int j=0;j<10;j++)
           tree[i][j]=0;
    }
   tot=0;//RE有可能是这里的问题
}

