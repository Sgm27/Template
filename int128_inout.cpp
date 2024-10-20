#include<bits/stdc++.h>
#ifdef DS
	#include "debug.h"
#else 
	#define deb(...) 
#endif
#define bigint __int128_t
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
istream& operator>>(istream& in, __int128_t& x)
{
    string s;
    in >> s;
    x = 0;
    for (char c : s)
    {
        x = x * 10 + (c - '0');
    }
    return in;
}
ostream& operator<<(ostream& out, __int128_t x)
{
    if (x == 0)
    {
        out << '0';
        return out;
    }
    string s;
    while (x > 0)
    {
        s += '0' + (x % 10);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    out << s;
    return out;
}
signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("thu.inp","r",stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	bigint a,b; cin>>a>>b;
	cout<<a+b;
}
