#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 100005
int n;
string s;
int nearest_left[maxn],nearest_right[maxn];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n>>s;
        s = "#" + s + "#";
        nearest_left[0] = 0;
        FOR(i,1,n) 
            if (isalpha(s[i])) nearest_left[i] = i;
            else nearest_left[i] = nearest_left[i-1];
        nearest_right[n+1] = n+1;
        FOD(i,n,1)
            if (isalpha(s[i])) nearest_right[i] = i;
            else nearest_right[i] = nearest_right[i+1];
        int idx = 1,ans = 0;
        while (idx <= n)
        {
            if (s[idx] != '.') 
            {
                idx++;
                continue;
            }
            if (s[nearest_left[idx]] == 'L' && s[nearest_right[idx]] == 'R') ans++;
            if (s[nearest_left[idx]] == '#' && s[nearest_right[idx]] == 'R') ans++;
            if (s[nearest_left[idx]] == 'L' && s[nearest_right[idx]] == '#') ans++;
            if (s[nearest_left[idx]] == 'R' && s[nearest_right[idx]] == 'L') 
            {
                if ((nearest_right[idx] - nearest_left[idx]) % 2 == 0) ans++;
                idx = nearest_right[idx];
            }
            idx++;
        }
        cout<<ans<<"\n";
    }
}
