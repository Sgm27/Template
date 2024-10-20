#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" ms"
#define int long long
#define pii pair<int,int>
#define maxn 
int n,q;
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    vector<int> a(n+1),p(n+1,0);
    FOR(i,1,n) cin>>a[i], p[i]=p[i-1]+a[i];
    while (q--)
    {
        int t,x,k;
        cin>>t>>x>>k;
        if (t)
            cout<<p[x]-p[x-k]<<"\n";
        else 
            cout<<p[k]<<"\n";
    }
}
