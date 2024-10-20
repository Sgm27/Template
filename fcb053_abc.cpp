#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" ms"
#define int long long
#define pii pair<int,int>
const int N=1e6;
#define maxn N+5
int cnt[maxn];
void eratos()
{
    FOR(i,1,sqrt(N))
        for (int j=i*i;j<=N;j+=i) 
        {
            cnt[j]++;
            if (j/i!=i) cnt[j]++;
        }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n; cin>>n;
    eratos();
    int ans=0;
    FOR(i,1,n-1) 
        ans+=cnt[i];
    cout<<ans;
}
