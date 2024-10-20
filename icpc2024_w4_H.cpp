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
#define maxn 1000006 
int n,m,a,c;
int x[maxn];
int get(int l,int r,int pre_val,int min_val,int max_val,int state)
{
	deb(l,r,pre_val,min_val,max_val,state)
	if (l > r) return 0;
	int m = l+r >> 1;
	int res = 0;
	if (x[m] > pre_val && x[m] > min_val && x[m] < max_val && state == 1) res++;
	if (x[m] < pre_val && x[m] > min_val && x[m] < max_val && state == 0) res++;
	res += get(l,m-1,x[m],min_val, min(x[m], max_val), 0);
	res += get(m+1,r,x[m],max(x[m], min_val), max_val, 1);
	return res;
}
signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("thu.inp","r",stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n>>m>>a>>c>>x[0];
	FOR(i,1,n)
		x[i] = (a * x[i-1] + c) % m;
	int m = 1+n >> 1;
	cout<<1 + get(1,m-1,x[m],-INF, x[m], 0) + get(m+1,n,x[m], x[m], INF, 1);
}
