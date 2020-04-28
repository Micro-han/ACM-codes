#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
ll read(){
    ll f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
int round_x,round_y,round_r;
int ts_x,ts_y,ts_len;
bool pInC(int x,int y,int r,int dx,int dy){
	int ddx = dx - x;
	int ddy = dy - y;
	return ddx * ddx + ddy * ddy < r * r;
}
bool pInS(int X, int Y, int len, int x, int y) {
	if(x>X && x<X+len && y>Y && y<Y+len)return 1;
	return 0;
}
bool cover(){
	if(pInC(round_x,round_y,round_r,ts_x,ts_y))return 1;
	if(pInC(round_x,round_y,round_r,ts_x+ts_len,ts_y))return 1;
	if(pInC(round_x,round_y,round_r,ts_x,ts_y+ts_len))return 1;
	if(pInC(round_x,round_y,round_r,ts_x+ts_len,ts_y+ts_len))return 1;
	if(pInS(ts_x,ts_y,ts_len,round_x-round_r,round_y))return 1;
	if(pInS(ts_x,ts_y,ts_len,round_x+round_r,round_y))return 1;
	if(pInS(ts_x,ts_y,ts_len,round_x,round_y-round_r))return 1;
	if(pInS(ts_x,ts_y,ts_len,round_x,round_y+round_r))return 1;
	if(pInS(ts_x,ts_y,ts_len,round_x,round_y))return 1;
	return 0;
}
bool pOnC(int x,int y,int r,int X,int Y){
	int dx=X-x,dy=Y-y;
	return dx*dx+dy*dy==r*r; 
} 
bool pOnS(int X,int Y,int len,int x,int y){
	if(x==X && y>=Y && y<=Y+len)return 1;
	if(x==X+len && y>=Y && y<=Y+len)return 1;
	if(x>=X && x<=X+len && y==Y)return 1;
	if(x>=X && x<=X+len && y==Y+len)return 1;
	return 0;
}
bool touch(){
	if(pOnC(round_x,round_y,round_r,ts_x,ts_y))return 1;
	if(pOnC(round_x,round_y,round_r,ts_x+ts_len,ts_y))return 1;
	if(pOnC(round_x,round_y,round_r,ts_x,ts_y+ts_len))return 1;
	if(pOnC(round_x,round_y,round_r,ts_x+ts_len,ts_y+ts_len))return 1;
	if(pOnS(ts_x,ts_y,ts_len,round_x-round_r,round_y))return 1;
	if(pOnS(ts_x,ts_y,ts_len,round_x+round_r,round_y))return 1;
	if(pOnS(ts_x,ts_y,ts_len,round_x,round_y-round_r))return 1;
	if(pOnS(ts_x,ts_y,ts_len,round_x,round_y+round_r))return 1;
	return 0;
}
int main(){
	scanf("%d%d%d",&round_x,&round_y,&round_r);
	scanf("%d%d%d",&ts_x,&ts_y,&ts_len);
	if (cover())puts("2");
	else if(touch())puts("1");
	else puts("0");
	return 0;
}

