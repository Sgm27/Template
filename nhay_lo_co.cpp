#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 50005
int L,n,have,a[maxn];
int f(int x)
{
	int pre_pos = 1, pre_val = 0, ans = 0;
	while (1)
	{
		auto pos = lower_bound(a+1,a+1+n,pre_val+x);
		if (pos == a+1+n) return ans + n - pre_pos;
		ans += (pos - a - pre_pos - 1);
		pre_pos = pos - a;
		pre_val = *pos;
	}
}
signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("thu.inp","r",stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>L>>n>>have;
	FOR(i,1,n) cin>>a[i];
	n+=2;
	a[n-1] = 0, a[n] = L;
	sort(a+1,a+1+n);
	int l = 0, r=L+1;
	while (r-l>1)
	{
		int m = l+r >> 1;
		if (f(m)<=have) l=m;
		else r=m;
	}
	cout<<l;
}
