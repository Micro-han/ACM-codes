//next[i]表示在s串中以 i 为起点的串的前缀与s串中的前缀最大匹配长度
void getNext(char *s,int next[]){
    int nn = strlen(s);
    next[0] = nn;
    int p = 0;
    while (p+1 < nn && s[p] == s[p+1]) p++;
    next[1] = p;
    int k = 1, L;
    for (int i = 2; i < nn; i++){
        p =     k + next[k] - 1; L = next[i - k];
        if (i + L <= p) next[i] = L;
        else {
            int j = p - i + 1;
            if (j < 0) j = 0;
            while (i + j < nn && s[i + j] == s[j]) j++;
            next[i] = j; k = i;

        }
    }
/*    for (int i=0;i<nn;i++){
        cout<< next[i] <<" ";
    }cout<<endl;
*/
}
//extend[i]表示s[i]...s[n-1]与T的最长相同前缀的长度
void getExtend(char *s,char *T,int extend[]){
    int nn = strlen(s) ,mm = strlen(T);
    getNext(s,next);
    int p = 0;
    while (p < nn && s[p] == T[p]) p++;
    extend[0] = p;
    //extend[1] = p;
    int k = 0, L;
    for (int i = 1; i < nn; i++){
        p =     k + extend[k] - 1; L = next[i - k];
        if (i + L <= p) extend[i] = L;
        else {
            int j = p - i + 1;
            if (j < 0) j = 0;
            while (i + j < nn && s[i + j] == T[j]) j++;
            extend[i] = j; k = i;

        }
    }
/*    for (int i=0;i<nn;i++){
        cout<< extend[i] <<" ";
    }cout<<endl;
*/
}