#include<math.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream> 
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
struct Point{
	double x,y;
};
Point p[maxn],a[maxn],b[maxn],t[maxn];
int n,m;
double A,B,C;
void GetLine(Point a,Point b){//��ֱ�� 
	A=b.y-a.y;
	B=a.x-b.x;
	C=b.x*a.y-a.x*b.y;
}
Point interpoint(Point a,Point b){//��ֱ���󽻵� 
	double x=fabs(A*a.x+B*a.y+C);
	double y=fabs(A*b.x+B*b.y+C);
	Point ans;
	ans.x=(a.x*y+b.x*x)/(x+y);
	ans.y=(a.y*y+b.y*x)/(x+y);
	return ans;
}
void cut(){
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(A*a[i].x+B*a[i].y+C>=0)b[++cnt]=a[i];
		else{
			if(A*a[i-1].x+B*a[i-1].y+C>0)b[++cnt]=interpoint(a[i-1],a[i]);
			if(A*a[i+1].x+B*a[i+1].y+C>0)b[++cnt]=interpoint(a[i],a[i+1]);
		}
	}
	for(int i=1;i<=cnt;i++)a[i]=b[i];
	a[0]=b[cnt];a[cnt+1]=b[1];
	m=cnt;
}
void solve(){
	for(int i=1;i<=n;i++)a[i]=p[i];
	p[n+1]=p[1];a[n+1]=p[1];a[0]=p[n];
	m=n;
	for(int i=1;i<=n;i++){
		GetLine(p[i],p[i+1]);
		cut();
	}
}
void init(){//�����Ϊ��ʱ�� 
	for(int i=1;i<=n;i++)t[i]=p[n-i+1];
	for(int i=1;i<=n;i++)p[i]=t[i];
}
int main(){
	while(~scanf("%d",&n)){
		if(!n)break;
		for(int i=1;i<=n;i++){
			double x,y;
			scanf("%lf%lf",&x,&y);
			p[i].x=x,p[i].y=y;
		}
		init();
		solve();
		if(m)puts("1");
		else puts("0");
	}
	return 0;
}

/*
˫�˶������ƽ�潻nlgn 
struct Point{//��ı�ʾ 
	double x,y;
	Point(double _x=0,double _y=0){
		x=_x;y=_y;
	}
	friend Point operator + (const Point &a,const Point &b){
		return Point(a.x+b.x,a.y+b.y); 
	}
	friend Point operator - (const Point &a,const Point &b){
		return Point(a.x-b.x,a.y-b.y);
	}
	friend Point operator == (const Point &a,const Point &b){
		return fabs(a.x-b.x)<EPS&&fabs(a.y-b.y)<EPS;
	}
}convex[MAXN];
struct V{//�����ı�ʾ 
	Point start,end;
	double ang;//�Ƕȣ�[-180,180] 
	V(Point _start=Point(0,0),Point _end=Point(0,0),double _ang=0){
		start=_start;end=_end;ang=_ang;
	}
	friend V operator + (const V &a,const V &b){
		return V(a.start+b.start,a.end+b.end);
	}
	friend V operator - (const V &a,const V &b){
		return V(a.start-b.start,a.end-b.end);
	} 
}l[MAXN],st[MAXN];
struct Triangle{
	Point A,B,C;
};
int n,ccnt;
double DotMul(V a,V b){//��� 
	a.end=a.end-a.start;b.end=b.end-b.start;
	return a.end.x*b.end.x+a.end.y*b.end.y;
}
double CroMul(V a,V b){//��� a��b 
	a.end=a.end-a.start;b.end=b.end-b.start;
	return a.end.x*b.end.y-b.end.x*a.end.y;
}
int IsLineInter(V l1,V l2){//�ཻ 
	if(max(l1.start.x,l1.end.x)>=min(l2.start.x,l2.end.x)&&
	max(l2.start.x,l2.end.x)>=min(l1.start.x,l1.end.x)&&
	max(l1.start.y,l1.end.y)>=min(l2.start.y,l2.end.y)&&
	max(l2.start.y,l2.end.y)>=min(l1.start.y,l1.end.y)){
		if(CroMul(l2,V(l2.start,l1.start))*CroMul(l2,V(l2.start,l1.end))<=0&&
		CroMul(l1,V(l1.start,l2.start))*CroMul(l1,V(l1.start,l2.end))<=0){
			return 1;
		}
	}return 0;
}
Point LineInterDot(V l1,V l2){//���� 
	Point p;
	double S1=CroMul(V(l1.start,l2.end),V(l1.start,l2.start));
	double S2=CroMul(V(l1.end,l2.start),V(l1.end,l2.end));
	p.x=(l1.start.x*S2+l1.end.x*S1)/(S1+S2);
	p.y=(l1.start.y*S2+l1.end.y*S1)/(S1+S2);
	return p;
}
int JudgeOut(const V &x,const Point &p){//�����ߵ���� 
	return CroMul(V(x.start,p),x)>EPS;//������෵��0,�Ҳ෵��1 
}
int Parellel(const V &x,const V &y){//ƽ�� 
	return fabs(CroMul(x,y))<EPS;
}
int Cmp(V a,V b){
	if(fabs(a.ang-b.ang)<EPS){//�Ƕ���ͬʱ����ͬ�ı��ڲ�ͬ��λ�� 
		//��ʱ������return��ʽ�� 
		//return CorMul(a,V(b.end-a.start))>=0;
		//��ߵı��ں����λ�ã������Ļ������м����ʱ��Ϳ��Ժ��� ��ͬ�Ƕȱߵ�Ӱ���� 
		return CroMul(V(b.end-a.start),V(a.end-b.start))>EPS;
		//��ߵı���ǰ���λ�ã�Ҫ���н���ȥ���ж� �� 
	}
	return a.ang<b.ang;
}
double HplaneIntersection(){
	int top=1,bot=0;
	sort(l,l+n,Cmp);
	int tmp=1;
	for(int i=1;i<n;++i){
		if(l[i].ang-l[i-1].ang>EPS){//ȥ��,����ñߺ�ǰ��ı�ƽ�У�����ԡ� 
			l[tmp++]=l[i];
		}
	}n=tmp;
	st[0]=l[0];st[1]=l[1];
	for(int i=2;i<n;++i){
		if(Parellel(st[top],st[top-1])||Parellel(st[bot],st[bot+1])) return 0;
		while(bot<top&&JudgeOut(l[i],LineInterDot(st[top],st[top-1]))) --top;
		while(bot<top&&JudgeOut(l[i],LineInterDot(st[bot],st[bot+1]))) ++bot;
		st[++top]=l[i];
	}
	while(bot<top&&JudgeOut(st[bot],LineInterDot(st[top],st[top-1]))) --top;
	while(bot<top&&JudgeOut(st[top],LineInterDot(st[bot],st[bot+1]))) ++bot;
	if(top<=bot+1) return 0.00;
	st[++top]=st[bot];
	ccnt=0;
	for(int i=bot;i<top;++i){
		convex[ccnt++]=LineInterDot(st[i],st[i+1]);
	}double ans=0;
	convex[ccnt]=convex[0];
	for(int i=0;i<ccnt;++i){
		ans+=CroMul(V(Point(0,0),convex[i]),V(Point(0,0),convex[i+1]));
	}return ans/2;
}
*/
