#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 1000006
int n;
string s;
vector<int> calc_Z(string s)
{
    n=s.length();
    vector<int> z(n+1);
    s=" "+s;    
    z[1]=0;
    int l,r=0;
    for (int i=2;i<=n;i++)
    {
        int x=0;
        if (i<=r) x=min(z[i-l+1],r-i+1);
        while (i+x<=n && s[x+1]==s[i+x]) x++;
        z[i]=x;
        if (r < i+x-1)
        {
            r=i+x-1;
            l=i;
        }
    }
    return z;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc,ntest=0; cin>>tc;
    while (tc-- && ++ntest)
    {
        int answer=0;
        cin>>s;
        vector<int> ans=calc_Z(s);
        FOR(i,1,n)
            if (i+ans[i]-1 == n) answer++;
        cout<<"Case "<<ntest<<": "<<answer<<"\n";
    }
}
