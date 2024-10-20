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
int n;
string s;
int cong, tru;
int lcm(int a,int b)
{
	return a / __gcd(a,b) * b;
}
void solve(int a,int b)
{
	int l = lcm(a,b);
	if (a < b) swap(a,b);
	int nc = cong, nt = tru;
	if (nc > nt) swap(nc, nt);
	int dec_cong = l / a, dec_tru = l / b;
	while (1)
	{
		if (nc < 0 || nt < 0) break;
		if (nt == nc) 
		{
			cout<<"YES\n";
			return;
		}
		nc -= dec_cong;
		nt -= dec_tru;
	}
	cout<<"NO\n";
}
signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("thu.inp","r",stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n>>s;
	for (char c : s)
		if (c == '+') cong++;
		else tru++;
	int q; cin>>q;
	while (q--)
	{
		int a,b; cin>>a>>b;
		solve(a,b);
	}
}
