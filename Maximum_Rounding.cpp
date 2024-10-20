#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 1005

signed main()
{
    #ifndef ONLINE_JUDGE
    // freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; tc=1;
    while (tc--)
    {
        string s; cin>>s;
        int n=s.length(), last_round=n;
        s=" "+s;
        int idx=n;
        while (idx>0)
        {
            if (s[idx]>='5') 
            {
                if (s[idx]>='9') 
                {
                    s[idx]='0';
                    idx--;
                    while (idx>0 && s[idx]=='9') idx--;
                    idx++;
                }
                s[idx]='0';
                s[idx-1]+=1;
                last_round=idx;   
            }
            idx--;
        }
        if (s[1]=='0') cout<<"1";
        FOR(i,1,last_round) cout<<s[i];
        FOR(i,last_round+1,n) cout<<"0";
        cout<<"\n";
    }
}
