#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
map<ll, int>m;
const int mod = 10000019;
const int times = 50;//����50��
ll mul(ll a, ll b, ll m){//��a*b%m
    ll ans = 0;
    a %= m;
    while(b){
        if(b & 1)ans = (ans + a) % m;
        b /= 2;
        a = (a + a) % m;
    }
    return ans;
}
ll pow(ll a, ll b, ll m){//a^b % m
    ll ans = 1;
    a %= m;
    while(b){
        if(b & 1)ans = mul(a, ans, m);
        b /= 2;
        a = mul(a, a, m);
    }
    ans %= m;
    return ans;
}
bool Miller_Rabin(ll n, int repeat){//n�ǲ��ԵĴ�����repeat�ǲ����ظ�����
    if(n == 2 || n == 3)return true;//����
    if(n % 2 == 0 || n == 1)return false;//ż����1
    //��n-1�ֽ��2^s*d
    ll d = n - 1;
    int s = 0;
    while(!(d & 1)) ++s, d >>= 1;
    //srand((unsigned)time(NULL));���ʼ���ü���
    for(int i = 0; i < repeat; i++){//�ظ�repeat��
        ll a = rand() % (n - 3) + 2;//ȡһ�������,[2,n-1)
        ll x = pow(a, d, n);
        ll y = 0;
        for(int j = 0; j < s; j++){
            y = mul(x, x, n);
            if(y == 1 && x != 1 && x != (n - 1))return false;
            x = y;
        }
        if(y != 1)return false;//����С����
    }
    return true;
}
ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}
ll pollard_rho(ll n, ll c){//�ҵ�n��һ������
    ll x = rand() % (n - 2) + 1;
    ll y = x, i = 1, k = 2;
    while(1){
        i++;
        x = (mul(x, x, n) + c) + n;//���ϵ���x2
        ll d = gcd(y - x, n);
        if(1 < d && d < n)
            return d;//�ҵ�����
        if(y == x)
            return n;//�ҵ�ѭ��������n��������
        if(i == k)//һ���Ż�
        {
            y = x;
            k <<= 1;
        }
    }
}
void Find(ll n, ll c){
    if(n == 1)return;//�ݹ����
    if(Miller_Rabin(n, times)){//������������ͼ���
        m[n]++;
        return;
    }

    ll p = n;
    while(p >= n)
        p = pollard_rho(p, c--);//���������ӣ�֪���ҵ�Ϊֹ������n˵��û�ҵ�
    Find(p, c);
    Find(n / p, c);
}
int main(){
    ll n;srand((unsigned)time(NULL));
    while(cin >> n){
        m.clear();
        Find(n, rand() % (n - 1) + 1);//�����Լ����õ�һ����
        cout<<n<<" = ";
        for(map<ll ,int>::iterator it = m.begin(); it != m.end();){
            cout<<it->first<<" ^ "<<it->second;
            if((++it) != m.end())
               cout<<" * ";
        }
        cout<<endl;
    }
    return 0;
}
