//�����ַ����Ƚ϶��Ҫͳ�Ƹ����ģ�map����������£�ֱ�����ֵ���
//�ܶ��ⶼ��Ҫ�õ��ڵ��±�����ʾĳ���ַ���
const int maxn =2e6+5;//�����64MB���Կ���2e6+5����������
int tree[maxn][30];//tree[i][j]��ʾ�ڵ�i�ĵ�j�����ӵĽڵ���
bool flagg[maxn];//��ʾ�Ըýڵ��β��һ������
int tot;//�ܽڵ���
int sum[maxn];//sum[rt]��ʾ��ǰ�ַ�����β�ڵ�ķ��ʴ��� 
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
void init()//�����գ���ʡʱ��
{
    for(int i=0;i<=tot;i++)
    {
       flagg[i]=false;
       for(int j=0;j<10;j++)
           tree[i][j]=0;
    }
   tot=0;//RE�п��������������
}

