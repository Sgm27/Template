#ifdef DS
    #include "debug.h"
#else 
    #include<bits/stdc++.h>
    #define deb(...) 
#endif
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
using ld = long double;
ld eps = 1e-9;

struct Point {
    ld x, y;
};

ld determinant(ld a, ld b, ld c, ld d, ld e, ld f, ld g, ld h, ld i) {
    return a*(e*i - f*h) - b*(d*i - f*g) + c*(d*h - e*g);
}

std::pair<Point, ld> circleFromThreePoints(Point A, Point B, Point C) {
    ld x1 = A.x, y1 = A.y;
    ld x2 = B.x, y2 = B.y;
    ld x3 = C.x, y3 = C.y;

    // Ma trận đầu tiên
    ld D = determinant(x1, y1, 1, x2, y2, 1, x3, y3, 1);
    
    if (D == 0) {
        // std::cerr << "Các điểm thẳng hàng, không thể xác định đường tròn ngoại tiếp." << std::endl;
        return {{0, 0}, -1};  // Trả về một giá trị báo lỗi
    }

    // Ma trận thứ hai và thứ ba để tìm Dx và Dy
    ld Dx = determinant(x1*x1 + y1*y1, y1, 1, x2*x2 + y2*y2, y2, 1, x3*x3 + y3*y3, y3, 1);
    ld Dy = determinant(x1, x1*x1 + y1*y1, 1, x2, x2*x2 + y2*y2, 1, x3, x3*x3 + y3*y3, 1);

    // Tính tọa độ tâm
    ld x_c = Dx / (2 * D);
    ld y_c = Dy / (2 * D);

    // Tính bán kính
    ld radius = std::sqrt((x1 - x_c)*(x1 - x_c) + (y1 - y_c)*(y1 - y_c));

    return {{x_c, y_c}, radius};
}

ld dist(Point A,Point B)
{
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

void solve()
{
    int n,k; cin>>n>>k;
    vector<Point> a(n+1);
    FOR(i,1,n)
        cin>>a[i].x>>a[i].y;
    FOR(i,1,n)
        FOR(j,i+1,n)
            FOR(kk,j+1,n)
            {
                auto [center, radius] = circleFromThreePoints(a[i], a[j], a[kk]);
                int cnt = 0;
                // deb(radius)
                FOR(ii,1,n)
                {
                    ld dis = dist(a[ii], center);
                    if (abs(dis - radius) < eps) continue;
                    if (dis < radius) cnt++;
                }
                if (cnt == k)
                {
                    cout<<"YES\n";
                    return;
                }
            }
    cout<<"NO\n";
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    int tc; cin>>tc;
    while (tc--)
    {
        solve();	
    }
}
