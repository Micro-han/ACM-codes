#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int maxn = 1e6+10;
struct Tpoint{
    double x,y;
};
typedef pair<double,double> pdd;
pdd now[maxn];
struct Tcircle{
    Tpoint p;
    double r;
};

Tpoint operator -(Tpoint x,Tpoint y){
    Tpoint tmp;
    tmp.x = x.x-y.x;tmp.y = x.y-y.y;
    return tmp;
}
Tpoint operator +(Tpoint x,Tpoint y){
    Tpoint tmp;
    tmp.x = x.x+y.x;tmp.y = x.y+y.y;
    return tmp;
}
Tpoint operator *(Tpoint x,double d){
    Tpoint tmp ;
    tmp.x = x.x*d;tmp.y = x.y*d;
    return tmp;
}
Tpoint operator /(Tpoint x,double d){
    Tpoint tmp ;
    tmp.x = x.x/d;tmp.y = x.y/d;
    return tmp;
}
double operator *(Tpoint x,Tpoint y){
    return x.x*y.x + x.y*y.y;
}
double operator ^(Tpoint x,Tpoint y){
    return x.x*y.y-x.y*y.x;
}
double dis0(Tpoint a){
    return sqrt(a.x*a.x+a.y*a.y);
}

int sign(double k){
    if(fabs(k) < eps)  return 0;
    return k > 0 ? 1:-1;
}

double getpoint(Tpoint ap,double ar,Tpoint bp,double br){
    double d = dis0(ap-bp);
    double cos_t = (ar*ar+d*d-br*br)/(2*ar*d);
    return cos_t;
}
int m,n;
Tcircle tcin[maxn],c[maxn];

void uni(){
    n=0;
    for(int i=1;i<=m;i++){
        bool covered=false;
        for(int j=1;j<=m;j++) if(i!=j){
            int tmpr=sign(tcin[j].r-tcin[i].r);
            int tmp=sign(dis0(tcin[i].p-tcin[j].p)-(tcin[j].r-tcin[i].r));
            if(tmp<=0){
                if(tmpr>0 || (tmpr==0&&j<i)) covered=true;
            }
        }
        if(!covered) c[++n]=tcin[i];
    }
}
double to_2pi(double x){
    if(x < 0)   return x+2*pi;
    else    return x;
}
void sov(){
    double ans = 0;
    for(int i = 1 ; i <= n ; i++){
        int cnt = 0;double a = c[i].p.x,b = c[i].p.y,r = c[i].r;
        for(int j = 1 ; j <= n ; j++){
            if(i == j) continue;
            if(sign(dis0(c[i].p-c[j].p)-(c[i].r+c[j].r)) >= 0) continue;
            double cos_t = getpoint(c[i].p,c[i].r,c[j].p,c[j].r);
            double stad,angle1,angle2;
            stad = atan2((c[j].p-c[i].p).y,(c[j].p-c[i].p).x);
            angle1 = to_2pi(stad - acos(cos_t));
            angle2 = to_2pi(stad + acos(cos_t));
            if(sign(angle2-angle1) >= 0){
                now[cnt++] = make_pair(angle1 , angle2);
            }
            else{
                now[cnt++] = make_pair(0.0 , angle2);
                now[cnt++] = make_pair(angle1 , 2*pi);
            }
        }

        sort(now,now+cnt);
        double right = 0;
        for(int k = 0 ; k < cnt ; k++){
            if(now[k].first > right){
                double low = right, up = now[k].first;
                ans += 0.5*r*r*(up-low) + 0.5*r*(a*(sin(up)-sin(low))-b*(cos(up)-cos(low)));
            }
            right = fmax(right , now[k].second);
        }
        double low = right,up = 2*pi;
        ans += 0.5*r*r*(up-low) + 0.5*r*(a*(sin(up)-sin(low))-b*(cos(up)-cos(low)));
    }
    printf("%.3f\n",ans);
}

int main(){
    scanf("%d",&m);
    for(int i = 1; i <= m; i++)
        scanf("%lf%lf%lf",&tcin[i].p.x,&tcin[i].p.y,&tcin[i].r);
    uni();
    sov();
}

