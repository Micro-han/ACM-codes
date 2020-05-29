#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
const int MAXN = 2000 + 7;
 
struct Point {
    Point(ll x = 0, ll y = 0) : x(x), y(y){}
    ll x, y;
    Point operator - (const Point &p) const {
        return Point(x - p.x, y - p.y);
    }
    ll operator * (const Point &p) const {      //    dot
        return x * p.x + y * p.y;
    }
    ll operator ^ (const Point &p) const {      //    det
        return x * p.y - y * p.x;
    }
    bool operator < (const Point &p) const {    //   angle sorting
        bool up[2] = {0, 0};
        if(y > 0 || (y == 0 && x > 0)) up[0] = 1;
        if(p.y > 0 || (p.y == 0 && p.x > 0)) up[1] = 1;
        if(up[0] ^ up[1]) return up[0];
        return (*this) ^ p ? ((*this) ^ p) > 0 : ((*this) * (*this)) < (p * p);
    }
}p[2020], vec[4020];
 
int main() {
    ios::sync_with_stdio(false);
    int n;
    while(cin >> n) {
        ll ans = 1LL * n * (n-1) *(n-2) / 6, tmp = 0;
        ll tt=0;
        //  input data starts
        for(int i = 0; i < n; ++i) {
            cin >> p[i].x >> p[i].y;
        }
        //   input data ends
        //  solution start
        for(int i = 0; i < n; ++i) {
            int cnt = 0;
            for(int j = 0; j < n; ++j) {
                if(i == j) continue;
                vec[cnt++] = p[j] - p[i];
            }
            sort(vec, vec + cnt);
            for(int j = 0; j < cnt; ++j) {
                vec[j + cnt] = vec[j];
            }
            ll num = 0;
            for(int j = 1; j < cnt; ++j) {
                if((vec[j] ^ vec[j-1]) == 0 && vec[j] * vec[j-1] > 0) { //   共线
                    num++;
                }
                else num = 0;
                tmp += num;
            }
            int p1 = 0, p2 = 0;
            for(int j = 0; j < cnt; ++j) {
                //  vec[j]逆时针方向锐角数
                while(p1 <= j || (p1 < j + cnt && (vec[p1] ^ vec[j]) < 0 && (vec[p1] * vec[j]) >=0)) p1++;
                //=包含了直角和三点共线 
                //  vec[j]逆时针方向的锐角、直角、钝角数
                while(p2 <= j || (p2 < j + cnt && (vec[p2] ^ vec[j]) < 0)) p2++;
                ans -= p2 - p1;
                tt+=p2-p1;
            }
        }
        //  solution ends
        cout << tt  << endl;
    }
    return 0;
}
//钝角即p2-p1
//直角和锐角即C(n,3)-钝角-三点共线
//锐角即减去C(n,3)-钝角-直角-三点共线 

