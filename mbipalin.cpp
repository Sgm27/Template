#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 
int n,m,Pow,End,ans,x[25];
unordered_map<int,int> D;
void Try(int i,int type)
{
    int j = 0;
    if (i == 1 && type == 1) j = 1;
    for (;j<=9;j++)
    {
        x[i] = j;
        if (i == End)
        {
            int idx = End - (n%4 != 0);
            for (int k=End+1;k<=n/2;k++) x[k] = x[idx--];
            int curMod = 0;
            for (int k=1;k<=n/2;k++)
                curMod = (curMod * 10 + x[k]) %m;
            if (type == 1) 
                D[(curMod * Pow) % m]++;
            else
                ans += D[(m - curMod + m*m) %m];
        }
        else
            Try(i+1,type);
    }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    Pow = 1;
    FOR(i,1,n/2) Pow = (Pow * 10) %m;
    if (n == 2) 
    {
        FOR(i,10,99)
            if (i % m == 0) ans++;
        return cout<<ans, 0;
    }
    End = n/4 + (n%4 != 0);
    Try(1,1);
    Try(1,2);
    cout<<ans;
}
