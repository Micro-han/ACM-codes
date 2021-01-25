#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;
int n;
struct arr{
	ll x,y;
}a[N];
ll sum ,tmp,dx,dy,ans;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%lld%lld",&a[i].x,&a[i].y);
	for(int i=0;i<n;i++){
		tmp = a[i].x*a[(i+1)%n].y-a[i].y*a[(i+1)%n].x;
		sum += tmp;
		dx = abs(a[i].x-a[(i+1)%n].x);
		dy = abs(a[i].y-a[(i+1)%n].y);
		ans += __gcd(dx,dy);
	}
	printf("%lld\n",(abs(sum)-ans+2)/2);
	//S = n + s/2 -1; S面积s边上格点 n内部格点
	//线段上格点数量为(x1,y1) (x2,y2) gcd(|x1-x2|,|y1-y2|)+1
	//多边形面积 1/2*sum{op_i X op_i+1} 
	return 0;
} 
