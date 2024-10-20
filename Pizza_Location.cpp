#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 105 
int k,r,m,n;
struct data{
    int x,y,s;
} res[maxn], hou[maxn];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>k>>r;
    cin>>n;
    FOR(i,1,n) cin>>res[i].x>>res[i].y;
    cin>>m;
    FOR(i,1,m) cin>>hou[i].x>>hou[i].y>>hou[i].s;
    
}
