#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 50004
vector<int> pos[256];
string s;
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
        cin>>s;
        s=" "+s;
        for (int i=1;i<s.length();i++)
            pos[s[i]].push_back(i);
        int ans=0;
        int q; cin>>q;
        while (q--)
        {
            string t; cin>>t;
            int last_pos=0,flag=1;
            for (int i=0;i<t.length();i++)
            {
                auto p=upper_bound(pos[t[i]].begin(),pos[t[i]].end(),last_pos);
                if (p==pos[t[i]].end()) 
                {
                    flag=0;
                    break;
                }
                else last_pos=*p;
            }
            // if (flag) cout<<t<<" ";
            ans+=flag;
        }
        cout<<ans<<"\n";
        FOR(i,96,125) pos[i].clear();
    }
}
