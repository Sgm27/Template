//  WA on test 11
// http://lequydon.ntucoder.net/Problem/Details/5841/
#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 100003
int t1,t2,a[maxn],dp[maxn][11][2][2];
string l,r;

int thu(int i,bool gh,int last_dg,bool tang,bool nghia)
{
    if (!i) return 1;
    if (gh==false && dp[i][last_dg][tang][nghia]>=0) 
        return dp[i][last_dg][tang][nghia];
    int maxc=gh ? a[i] : 9,res=0;
    if (nghia)
    {
        if (tang)
        {
            for (int c=last_dg+1;c<=maxc;c++)
            {
                bool ghm=gh & c==maxc;
                res+=thu(i-1,ghm,c,false,true);
            }
        }
        else
        {
            for (int c=0;c<=min(maxc,last_dg-1);c++)
            {
                bool ghm=gh & c==maxc;
                res+=thu(i-1,ghm,c,true,true);
            }

        }
    }
    else
    {
        bool ghm=gh & 0==maxc;
        res+=thu(i-1,ghm,0,true,false);
        for (int c=1;c<=maxc;c++)
        {
            ghm=gh & c==maxc;
            res+=thu(i-1,ghm,c,true,true);
            if (i>1)
            res+=thu(i-1,ghm,c,false,true);
        }
    }   
    res%=MOD;
    if (gh==false) dp[i][last_dg][tang][nghia]=res;
    return res;
}
int G(string s)
{
    int n=0;
    if (s.length()==1) return s[0]-'0'+1;
    for (int i=s.length()-1;i>=0;i--)
        a[++n]=s[i]-'0';
    return thu(n,true,10,true,false);
}
void giam1(string &s)
{
    int n=s.length()-1;
    s[n]--;
    while (1)
    {
        if (!isdigit(s[n])) 
        {
            s[n]='9';
            n--;
            s[n]--;
        }
        else break;
    }
    if (s[0]=='0' && s.length()!=1) s.erase(s.begin());
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    memset(dp,-1,sizeof(dp));
    cin>>t1>>t2;
    cin>>l>>r;
    giam1(l); // l-=1;
    cout<<(G(r)-G(l) + MOD * MOD) %MOD<<"\n";
}
