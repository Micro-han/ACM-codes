struct L_B{
    long long d[61],p[61];
    int cnt;
    L_B()
    {
        memset(d,0,sizeof(d));
        memset(p,0,sizeof(p));
        cnt=0;
    }
    bool insert(long long val)
    {
        for (int i=60;i>=0;i--)
            if (val&(1LL<<i))
            {
                if (!d[i])
                {
                    d[i]=val;
                    break;
                }
                val^=d[i];
            }
        return val>0;
    }
    long long query_max()
    {
        long long ret=0;
        for (int i=60;i>=0;i--)
            if ((ret^d[i])>ret)
                ret^=d[i];
        return ret;
    }
    long long query_min()
    {
        for (int i=0;i<=60;i++)
            if (d[i])
                return d[i];
        return 0;
    }
    void rebuild()
    {
        for (int i=60;i>=0;i--)
            for (int j=i-1;j>=0;j--)
                if (d[i]&(1LL<<j))
                    d[i]^=d[j];
        for (int i=0;i<=60;i++)
            if (d[i])
                p[cnt++]=d[i];
    }
    long long kthquery(long long k)
    {
        int ret=0;
        if (k>=(1LL<<cnt))
            return -1;
        for (int i=60;i>=0;i--)
            if (k&(1LL<<i))
                ret^=p[i];
        return ret;
    }
}
L_B merge(const L_B &n1,const L_B &n2)
{
    L_B ret=n1;
    for (int i=60;i>=0;i--)
        if (n2.d[i])
            ret.insert(n1.d[i]);
    return ret;
}
/*
1.�����Ի�����򼯺��в�����00�� 
2.���Ի�����򼯺���ÿ��Ԫ�ص���򷽰�Ψһ����ʵ���������1�ǵȼ۵ġ� 
3.���Ի����������λ������ͬ�� 
4.������Ի������ģ�������򼯺�Ϊ[1,2n?1][1,2n?1]�� 
5.���Ի���Ԫ�ػ��������򼯺ϲ��䡣
*/
