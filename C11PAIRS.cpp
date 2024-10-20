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
	int n; cin>>n;
	vi a(n+1);
	FOR(i,1,n) cin>>a[i];
	stack<int> st;
	unordered_map<int,int> cnt;
	st.push(a.back());
	cnt[a.back()]++;
	int ans = 0;
	FOD(i,n-1,1)
	{
		if (a[i] < st.top()) 
		{
			ans++;
			st.push(a[i]);
			cnt[a[i]]++;
		}
		else
		{
			while (!st.empty() && a[i] > st.top()) 
			{
				ans++;
				cnt[st.top()]--;
				st.pop();
			}
			ans += cnt[a[i]];
			if (st.size() - cnt[a[i]] > 0) ans++;
			st.push(a[i]);
			cnt[a[i]]++;
		}
	}
	cout<<ans;
}
