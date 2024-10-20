#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
using ld = long double;
const int MOD=1e9+7,INF=9e18;
#define maxn 
int n;
ld a[15];
ld f(ld x)
{
	ld ans = a[0], xx = 1.0;
	FOR(i,1,n)
	{
		xx *= x;
		ans += a[i] * xx;
	}
	return ans;
}
signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("thu.inp","r",stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n;
	FOR(i,0,n) cin>>a[i];
	ld l = -1e6, r = 1e6;
	if (a[n] > 0)
	{
		FOR(i,1,150)
		{
			ld m = (l+r) / 2.0;
			if (f(m) < 0.0) l=m;
			else r = m;
		}
	}
	else
	{
		FOR(i,1,150)
		{
			ld m = (l+r) / 2.0;
			if (f(m) < 0.0) r=m;
			else l = m;
		}
	}
	cout<<(int) (1000 * l);
}
