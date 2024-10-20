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
#define maxn 1003
void manacher(string t)
{
    string s = ".";
    for (char c : t)
    {
        s += c;
        s += '.';
    }
    int n = s.length();
    vi d(n);
    int l = 0, r = -1;
    FOR(i,0,n-1)
    {
        int k = 0;
        if (i <= r)
            k = min(r-i, d[r-i+l]);
        while (i+k+1 < n && i-k-1 >= 0 && s[i+k+1] == s[i-k-1]) k++;
        d[i] = k;
        if (i+k > r)
            l = i-k, r = i+k;
    }
    int max_len = -1, pos;
    FOR(i,0,n-1)
        if (d[i] > max_len)
		{
			max_len = d[i];
			pos = i;
		}
	deb(s, pos)
    string ans = s.substr(pos - max_len + 1, max_len * 2 - 1);
	string new_ans = "";
	for (char c : ans)	
		if (c != '.') new_ans.push_back(c);
	cout<<new_ans;
}   
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc = 1;
    while (tc--)
    {
        string s; cin>>s;
        manacher(s);
    }
}
