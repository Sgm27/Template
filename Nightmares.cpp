#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 200005
string a[maxn];
int n,cnt[maxn][26],mask[maxn];
void sol()
{
	cin>>n;
	FOR(i,1,n) cin>>a[i];
	FOR(i,1,n)
        for (char c : a[i]) cnt[i][c-'a']++;
    FOR(i,1,n)
        FOR(j,0,25) mask[i] |= ((cnt[i][j] % 2) << j);
    int ans = 0;
    unordered_map<int,int> have;
    FOR(c,0,25)
    {
        have.clear();
        FOR(i,1,n)
            if (cnt[i][c] == 0)
            {
                ans += have[((1 << 26) - 1) ^ (1 << c) ^ mask[i]];
                have[mask[i]]++;
            }
    }
    cout<<ans;
}
signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("thu.inp","r",stdin);
    // freopen("thu.ans","w",stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	sol();
}
