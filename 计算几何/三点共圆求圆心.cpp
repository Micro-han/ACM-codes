void solve(arr a,arr b,arr c){//三点共圆求圆心
	double fm1=2*(a.x-c.y)*(a.x-b.x)-2*(a.y-b.y)*(a.x-c.x);
	double fm2=2*(a.y-b.y)*(a.x-c.x)-2*(a.y-c.y)*(a.x-b.x);
	if(fm1==0 || fm2==0){
		YX.x=dinf;
		YX.y=dinf;
		return;
	}
	double fz1=a.x*a.x-b.x*b.x+a.y*a.y-b.y*b.y;
	double fz2=a.x*a.x-c.x*c.x+a.y*a.y-c.y*c.y;
	YX.x=(fz1*(a.y-c.y)-fz2*(a.y-b.y))/fm1;
	YX.y=(fz1*(a.x-c.x)-fz2*(a.x-b.x))/fm2;
}