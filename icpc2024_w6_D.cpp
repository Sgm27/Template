#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) 28
#define write_output(...) 03
#define eprintf(...) 2003
#define endl '\n'
#endif

// Chờ em đến bao giờ khi mà em chẳng yêu tôi

#define int long long

struct Point{
	double x, y;
	Point(){}
	Point(double x, double y): x(x), y(y){}

	double euclidean_distance(const Point& other) const{
		return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
	}
};

const double epsilon = 1e-9;

vector<Point> intersection_points(const Point c1, double radius1, const Point c2, double radius2) {
	double dx = c2.x - c1.x;
	double dy = c2.y - c1.y;
    double d = sqrt(dx * dx + dy * dy);

	if(d > radius1 + radius2)
		return {};

	if(d < abs(radius1 - radius2))
		return {};

	dx /= d;
	dy /= d;

	double a = (radius1 * radius1 - radius2 * radius2 + d * d) / (2 * d);
	double px = c1.x + a * dx;
	double py = c1.y + a * dy;

	double h = sqrt(radius1 * radius1 - a * a);
	return {
		Point(px + h * dy, py - h * dx),
		Point(px - h * dy, py + h * dx)
	};
}

// viết tên biến dài cho quen sau đi làm đỡ ngại :v
void sieunhan283(){
	int n, k;
	cin >> n >> k;

	vector<Point> points(n);
	vector<int> c(n);
	for(int i = 0; i < n; ++i)
	{
        cin >> points[i].x >> points[i].y >> c[i];    
    }

	auto check = [&](double m) -> bool{
		vector<double> radius;	
        vector<Point> new_points;
		for(int i = 0; i < n; ++i)
		{
            if (c[i] != 0)
            {
                radius.push_back(m / c[i]);
                new_points.push_back(points[i]);
            }
        }


		// not candidate master :(
		vector<Point> candidate_points = new_points;
		for(int i = 0; i < radius.size(); ++i){
			for(int j = i + 1; j < radius.size(); ++j){
				vector<Point> intersection = intersection_points(new_points[i], radius[i], new_points[j], radius[j]);
				for(const Point& point: intersection){
					candidate_points.push_back(point);
				}
			}
		}	

		for(const Point& point: candidate_points){
			int circle_count = 0;
			for(int i = 0; i < radius.size(); ++i){
				double dist = point.euclidean_distance(new_points[i]);
				if(dist < radius[i] || abs(dist - radius[i]) < epsilon)
					++circle_count;
			}
			if(circle_count >= k)
				return true;
		}
		return false;
	};

	double res = 400000;
	for(double l = 0, r = 400000; r - l >= epsilon; ){
		double m = (l + r) / 2;
		if(check(m)){
			res = m;
			r = m;
		}else
			l = m;
	}	
	
	cout << fixed << setprecision(6) << res << endl;
}

signed main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int test = 1;
	//cin >> test;

	for(int itest = 1; itest <= test; ++itest){
		eprintf("------- Case %d -------\n", itest);
		sieunhan283();
		eprintf("----------------------\n");
	}
	eprintf("Output:\n");
	write_output();	

	return 0;
}

