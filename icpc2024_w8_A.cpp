#ifdef DS
    #include "debug.h"
#else 
    #include<bits/stdc++.h>
    #define deb(...) 
#endif
using namespace std;

struct Point {
    double x, y;
};

Point p[55];

double distSq(Point A, Point B) {
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

double dist(Point A, Point B) {
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

Point findCircumcenter(Point A, Point B, Point C) {
    double D = 2 * (A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
    
    double Ux = ((A.x * A.x + A.y * A.y) * (B.y - C.y) + (B.x * B.x + B.y * B.y) * (C.y - A.y) + (C.x * C.x + C.y * C.y) * (A.y - B.y)) / D;
    double Uy = ((A.x * A.x + A.y * A.y) * (C.x - B.x) + (B.x * B.x + B.y * B.y) * (A.x - C.x) + (C.x * C.x + C.y * C.y) * (B.x - A.x)) / D;
    
    Point circumcenter = {Ux, Uy};
    return circumcenter;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    int n; cin>>n;
    for (int i = 1; i <= n; i++) 
        cin>>p[i].x>>p[i].y;
    
    double min_r = 1e9;
    
    auto is_valid = [&](Point X, double r) -> bool
    {
        for (int i = 1; i <= n; i++)
            if (dist(X, p[i]) > r) return false;
        return true;
    };

    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++)
        {
            double r = dist(p[i], p[j]) / 2.0;
            Point tmp = {(p[i].x + p[j].x) / 2.0, (p[i].y + p[j].y) / 2.0};
            if (is_valid(tmp, r)) min_r = min(min_r, r);
        }
    
    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++)
            for (int k = j+1; k <= n; k++)
            {
                Point tmp = findCircumcenter(p[i], p[j], p[k]);
                double r = dist(tmp, p[i]);
                if (is_valid(tmp, r)) min_r = min(min_r, r);
            }
    cout<<fixed<<setprecision(6)<<min_r;
}
