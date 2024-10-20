#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 25
int s1,s2,End;
int n,a[maxn],ans;
unordered_map<int,int> save;
void Try(int i,int type)
{
    for (int j = 0;j<=2;j++)
    {
        if (j == 2) s2 += a[i];
        if (j == 1) s1 += a[i];
        if (i == End)
        {
            int diff = abs(s1-s2);
            if (type == 1)
                save[diff] = max(save[diff],max(s1,s2));
            else
                if (save[diff]) ans = max(ans,save[diff] + min(s1,s2));
        }
        else
            Try(i+1,type);
        if (j == 1) s1 -= a[i];
        if (j == 2) s2 -= a[i];
    }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    End = n/2;
    Try(1,1);
    End = n;
    Try(n/2 + 1,2);
    cout<<ans;
}
