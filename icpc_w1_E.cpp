#ifdef DS
    #include "debug.h"
#else 
    #include<bits/stdc++.h>
    #define deb(...) 
#endif
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define NALL(x) x.begin()+1,x.end()
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define vi vector<int>
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 

struct CHT{
	vector<int> m, b;
	int ptr = 0; 
	bool bad(int l1, int l2, int l3) { // returns intersect(l1, l3) <= intersect(l1, l2)
		return 1.0 * (b[l3] - b[l1]) * (m[l1] - m[l2]) <= 1.0 * (b[l2] - b[l1]) * (m[l1] - m[l3]);
	} 

	void add(int _m, int _b) { 
		m.push_back(_m);
		b.push_back(_b); 
		int s = m.size(); 
		while(s >= 3 && bad(s-3, s-2, s-1)) {
			s--; 
			m.erase(m.end()-2);
			b.erase(b.end()-2); 
		}
	}  
	int f(int i, int x) { return m[i]*x + b[i]; }

	int query(int x) {   
		if(ptr >= m.size()) ptr = m.size()-1;
		while(ptr < m.size()-1 && 
			f(ptr+1, x) < f(ptr, x)) ptr++; 
		return f(ptr, x); 
	}
} cht; 

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,x; cin>>n>>x;
    vi a(n+1);
    FOR(i,1,n) cin>>a[i];

    auto sq = [&](int val) -> int
    {
        return val * val;
    };

    vi dp(n+1, INF);
    dp[1] = 0;
    cht.add(-2 * a[1], sq(a[1]));
    FOR(i,2,n)
    {
        dp[i] = cht.query(a[i]) + sq(a[i]) + x;
        cht.add(-2 * a[i], dp[i] + sq(a[i]));
    }
    cout<<dp[n];
}
