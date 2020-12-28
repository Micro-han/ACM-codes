#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
const int N = 1e6 +10;
const double dinf=1e15;
const double eps=1e-6;
int n;
double R;

struct Point{
	double x,y;
	
	Point(double _x=0,double _y=0):x(_x),y(_y) {}
	
	Point operator -(const Point &op2) const {
		return Point(x-op2.x,y-op2.y);
	}
	
	Point operator +(const Point &op2) const {
		return Point(x+op2.x,y+op2.y);
	}
	
	Point operator /(const double d) const {
		return Point(x/d,y/d);
	}
	
	Point operator *(const double d) const{
		return Point(x*d,y*d);
	}
	
	double operator ^(const Point &op2) const {
		return x*op2.y-y*op2.x;
	}	
};
struct StraightLine{
	double A,B,C;
	StraightLine(double _a=0,double _b=0,double _c=0):A(_a),B(_b),C(_c){}
	Point cross(const StraightLine &a) const {
		double xx=-(C*a.B-a.C*B)/(A*a.B-B*a.A);
		double yy=-(C*a.A-a.C*A)/(B*a.A-a.B*A);
		return Point(xx,yy);
	}
};
inline double sqr(double x){
	return x*x;
}

inline double dis2(const Point &p1,const Point &p2){
	return sqr(p1.x-p2.x)+sqr(p1.y-p2.y);
}

inline double dis(const Point &p1,const Point &p2){
	return sqrt(dis2(p1,p2));
}

inline double mul(const Point &p1,const Point &p2,const Point &p3){
	return (p2-p1)^(p3-p1);
}

inline double circumcenter(const Point &p1,const Point &p2,const Point &p3,Point &p){
	p=p1+StraightLine(p3.x-p1.x,p3.y-p1.y,-dis2(p3,p1)/2.0).cross(StraightLine(p2.x-p1.x,p2.y-p1.y,-dis2(p2,p1)/2.0));
	return dis2(p,p1);
}

Point p1,p2,p3,p4,p;
Point pp[10];
int flag=0;
void solve(Point a,Point b,Point c,Point d){//三点共圆求圆心
    double r=circumcenter(a,b,c,p);
    if(fabs(dis2(p,d)-r)<eps)flag=1;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        for(int i=0;i<4;i++)scanf("%lf%lf",&pp[i].x,&pp[i].y);
        flag=0;
        solve(pp[0],pp[1],pp[2],pp[3]);
        solve(pp[0],pp[1],pp[3],pp[2]);
        solve(pp[0],pp[2],pp[3],pp[1]);
        solve(pp[1],pp[2],pp[3],pp[0]);
        if(flag)puts("yes");
        else puts("no");

    }
    return 0;
}
