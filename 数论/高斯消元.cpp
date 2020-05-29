#include <algorithm>
#include <cstring>
#include <cmath>
#define nmax 100
using namespace std;
int a[nmax][nmax];
int x[nmax];
int free_x[nmax];
int gcd(int a,int b){
    if(!b) return a; else return gcd(b,a%b);
}
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
int Gauss(int equ,int var){
    int k,max_r,col = 0,ta,tb;
    int LCM,temp,num = 0,free_index;
    for(int i=0;i<=var;i++){
        x[i]=0;
        free_x[i]=true;
    }
    for(k = 0;k < equ && col < var;k++,col++){
        max_r=k;
        for(int i=k+1;i<equ;i++){
            if(abs(a[i][col])>abs(a[max_r][col])) max_r=i;
        }
        if(max_r!=k){// ���k�н���.
            for(int j=k;j<var+1;j++) swap(a[k][j],a[max_r][j]);
        }
        if(a[k][col]==0){// ˵����col�е�k������ȫ��0�ˣ�����ǰ�е���һ��.
            free_x[num++] = col;
            k--;
            continue;
        }
        for(int i=k+1;i<equ;i++){// ö��Ҫɾȥ����.
            if(a[i][col]!=0){
                LCM = lcm(abs(a[i][col]),abs(a[k][col]));
                ta = LCM/abs(a[i][col]);
                tb = LCM/abs(a[k][col]);
                if(a[i][col]*a[k][col]<0)tb=-tb;//��ŵ���������
                for(int j=col;j<var+1;j++){
                    a[i][j] = a[i][j]*ta-a[k][j]*tb;
                }
            }
        }
    }
    //�޽�
    for (int i = k; i < equ; i++){
        if (a[i][col] != 0) return -1;
    }
    //�����
    if (k < var){
        return var - k; // ���ɱ�Ԫ��var - k��.
    }
    //Ψһ��
    for (int i = var - 1; i >= 0; i--){
        temp = a[i][var];
        for (int j = i + 1; j < var; j++){
            if (a[i][j] != 0) temp -= a[i][j] * x[j];
        }
        if (temp % a[i][i] != 0) return -2; // ˵���и������⣬����������.
        x[i] = temp / a[i][i];
    }
    return 0;
}//����������

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 1010;
const double EPS=1e-7;
int m,n;
double a[N][N],x[N];
int Gauss(int m,int n){
    int col=0, k=0;//colΪ�к�,kΪ�к�
    for (;k<m&&col<n;++k,++col){
        int r = k;
        for (int i=k+1;i<m;++i)
            if(fabs(a[i][col])>fabs(a[r][col]))r=i;
        if (fabs(a[r][col])<EPS){k--;continue;}//��ȫΪ0
        if (r!=k)for(int i=col;i<=n;++i)
            swap(a[k][i],a[r][i]);
        for (int i=k+1;i<m;++i)//��Ԫ
            if(fabs(a[i][col])>EPS){
            double t = a[i][col]/a[k][col];
            for (int j=col;j<=n;j++)a[i][j]-=a[k][j]*t;
            a[i][col] = 0;
        }
    }
    for(int i=k ;i<m ;++i)//�޽�
        if (fabs(a[i][n])>EPS) return -1;
    if (k < n) return n - k;  //����Ԫ����
    for (int i =n-1; i>=0; i--){//�ش����
        double temp = a[i][n];
        for (int j=i+1; j<n; ++j)
            temp -= x[j] * a[i][j];
        x[i] = (temp / a[i][i]);
    }
    return 0;
}//������������

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define nmax 35
using namespace std;
int a[nmax][nmax];
int x[nmax];
int hashback[nmax][nmax];
int free_x[nmax];
char mp[nmax][nmax];
int ans1,ans2;
int equ,var;
int Gauss(){
    int max_r;
    int col=0,num = 0;
    int k;
    for(int i = 0;i<=var;++i) x[i] = free_x[i] = 0;
    for(k = 0;k < equ && col < var;k++,col++){
        max_r=k;
        for(int i=k+1;i<equ;i++){
            if(abs(a[i][col])>abs(a[max_r][col])) max_r=i;
        }
        if(max_r!=k){
            for(int j=k ;j<var+1;j++) swap(a[k][j],a[max_r][j]);
        }
        if(a[k][col]==0){
            free_x[num++] = col;
            k--; continue;
        }
        for(int i=k+1;i<equ;i++){
            if(a[i][col]!=0){
                for(int j=col;j<var+1;j++){
                    a[i][j]^=a[k][j];;
                }
            }
        }
    }
    for(int i = k;i<equ;++i){
        if(a[i][col] != 0) return -1;
    }
    if(k < var) return var - k;
    for(int i = var - 1; i >= 0; i--){
        x[i]=a[i][var];
        for(int j = i + 1; j < var; j++){
            x[i] ^= ( a[i][j] && x[j]);
        }
    }
    return 0;
}
void enum_freex(int n,int & ans){
    int num = (1<<(n));
    ans = 1e9+7;
    for(int i = 0;i<num;++i){
        int cnt = 0;
        for(int j = 0;j<n;++j){
            if(i&(1<<j)){
                cnt++;
                x[free_x[j]] = 1;
            }else x[free_x[j]] = 0;
        }
        for(int k = var-n-1;k>=0;--k){// û������Ԫ��������һ��
            int index = 0;
            for(index = k;k<var;index++){// �ڵ�ǰ���ҵ���һ����0����Ԫ(������ڵĻ�)
                if(a[k][index]) break;
            }
            x[index] = a[k][var];
            for(int j = index+1;j<var;++j){// ������μ�������
                if(a[k][j]) x[index] ^= x[j];
            }
            cnt += x[index]; // ������Ϊ1����ͳ��
        }
        ans = min(ans,cnt);
    }
}//��򷽳��� 
