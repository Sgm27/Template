#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18,N=100;
#define maxn 
int l,r,k,a[15],nt[N+5];
map<pair<pii,int>,int> dp;

void eratos()
{
    FOR(i,2,N) nt[i]=1;
    for (int i=2;i<=sqrt(N);i++)
        if (nt[i]) 
            for (int j=i*i;j<=N;j+=i) nt[j]=0;
}
int thu(int i,bool gh,int sum,int sodu)
{
    if (!i)
    {
        if (sodu==0 && nt[sum]) return 1;
        return 0;
    }
    pair<pii,int> X={{i,sum},sodu};
    if (gh==false && dp.count(X)) return dp[X];
    int maxc=gh ? a[i] : 9,res=0;
    for (int c=0;c<=maxc;c++)
    {
        bool ghm=gh & c==maxc;
        res+=thu(i-1,ghm,sum+c,(10*sodu+c)%k);
    }
    if (gh==false) dp[X]=res;
    return res;
}
int G(int x)
{
    int n=0;
    while (x)
    {
        a[++n]=x%10;
        x/=10;
    }
    return thu(n,true,0,0);
}
int check(int x)
{
    int sum=0;
    while (x)
    {
        sum+=x%10;
        x/=10;
    }
    return nt[sum];
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    eratos();
    cin>>l>>r>>k;
    if (k<=4000) cout<<G(r)-G(l-1);
    else
    {
        int ans=0;
        for (int i=(l/k+(l%k!=0))*k;i<=r;i+=k)
            ans+=check(i);
        cout<<ans;
    }
}
