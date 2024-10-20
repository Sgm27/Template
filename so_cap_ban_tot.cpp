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

signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("thu.inp","r",stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int n,k; 
	cin>>n>>k;
	vi a(n+1);
	FOR(i,1,n)
	{
		string s; cin>>s;
		a[i] = s.length();
	}
	map<int,int> cnt;
	int ans = 0;
	FOR(i,1,n)
	{
		cnt[a[i]]++;
		if (i > k) cnt[a[i-k-1]]--;
		ans += cnt[a[i]] - 1;
	}
	cout<<ans;
}
