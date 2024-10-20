#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
const int N=80;
#define maxn 
int dp[10][80],nt[85],a[10];
void eratos()
{
    FOR(i,1,N) nt[i]=1;
    nt[0]=nt[1]=0;
    FOR(i,2,sqrt(N)) 
        if (nt[i])
            for (int j=i*i;j<=N;j+=i) nt[j]=0;  
}
int thu(int i,bool gh,int tong)
{
    if (i == 0)
    {
        if (nt[tong]) return 1;
        return 0;
    }
    if (gh==false && dp[i][tong] != -1) return dp[i][tong];
    int maxc=gh ? a[i] : 9;
    int res=0;
    for (int c=0;c<=maxc;c++)
    {
        bool ghm=gh && c==maxc;
        res+=thu(i-1,ghm,tong+c);
    }
    if (gh==false) dp[i][tong]=res;
    return res;
}
// 1345
// 1 3 4 5
// 1 3 4 5
// i = 2;
// 2 gh = false
// 3 gh = true;
int G(int x)
{
    int n=0;
    while (x)
    {
        a[++n]=x%10;
        x/=10;
    }
    // thu(int i,bool gh, )
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
        memset(dp,-1,sizeof(dp));
        int A,B;
        cin>>A>>B;
        cout<<G(B)-G(A-1)<<"\n"; 	
    }
}
