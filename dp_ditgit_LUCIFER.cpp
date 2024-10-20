#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18,N=90;
#define maxn 
int a[15],nt[N+9];
map<pii,int> dp;
void eratos()
{
    FOR(i,2,N) nt[i]=1;
    for (int i=2;i<=sqrt(N);i++)
        if (nt[i])
            for (int j=i*i;j<=N;j+=i) nt[j]=0;
}
int thu(int i,bool gh,int hieu)
{
    if (!i)
    {
        if (hieu>0 && nt[hieu]) return 1;
        return 0;
    }
    if (gh==false && dp[{i,hieu}]>=0) return dp[{i,hieu}];
    int maxc=gh ? a[i] : 9;
    int res=0;
    for (int c=0;c<=maxc;c++)
    {
        bool ghm=gh & c==maxc;
        if (i%2) res+=thu(i-1,ghm,hieu-c);
        else res+=thu(i-1,ghm,hieu+c);
    }
    if (gh==false) dp[{i,hieu}]=res;
    return res;
}
int G(int x)
{
    int n=0;
    if (x<=0) return 0;
    while (x)
    {
        a[++n]=x%10;
        x/=10;
    }
    return thu(n,true,0);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    eratos();
    int tc; cin>>tc;
    while (tc--)
    {
        int l,r;
        cin>>l>>r; 	
        FOR(i,0,10) 
            FOR(j,-90,90) dp[{i,j}]=-1;
        cout<<G(r)-G(l-1)<<"\n";
    }
}
