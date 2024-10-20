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
#define maxn 20
int a[maxn];
pii dp[maxn][maxn][maxn][10];
pii getDP(int i,bool gh,int cnt6,int cnt8,int sodu)
{
	if (!i)
	{
		if (sodu == 0) 
			return pii(cnt6, cnt8);
		return {0,0};
	}
	if (gh == false && dp[i][cnt6][cnt8][sodu] != pii(-1, -1)) return dp[i][cnt6][cnt8][sodu];
	pii res = {0,0};
	int maxc = gh ? a[i] : 9;
	for (int c = 0; c <= maxc; c++)
	{
		bool ghm = gh & c == maxc;
		pii tmp = getDP(i-1, ghm, cnt6 + (c == 6), cnt8 + (c == 8), (sodu * 10 + c) % 8);
		res.first += tmp.first;
		res.second += tmp.second;
	}
	if (gh == false) 
		dp[i][cnt6][cnt8][sodu] = res;
	return res;
}
pii G(int x)
{
	FOR(i,0,19)
		FOR(c6,0,19)
			FOR(c8,0,19)
				FOR(du,0,7) dp[i][c6][c8][du] = pii(-1, -1);
	int n = 0;
	while (x)
	{
		a[++n] = x % 10;
		x /= 10;
	}
	return getDP(n, true, 0, 0, 0);
}
signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("thu.inp","r",stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int l,r; cin>>l>>r;
	pii ansr = G(r), ansl = G(l-1);
	cout<<ansr.first - ansl.first<<" "<<ansr.second - ansl.second;
}
