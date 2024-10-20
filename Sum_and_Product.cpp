#include<iostream>
#include<map>
#include<math.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define ll long long
#define pii pair<int,int>
#define maxn 200005
map<int,int> D;
int n,a[maxn],q;

bool cp(ll x)
{
    ll t=sqrt(x);
    if (t*t!=x) return false;
    return true;
}
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n;
        FOR(i,1,n) cin>>a[i], D[a[i]]++;
        cin>>q;
        while (q--)
        {
            ll x,y;
            cin>>x>>y;
            ll delta=x*x-4*y;
            if (delta<0 || !cp(delta)) 
            {
                cout<<0<<" ";
                continue;
            }
            delta=sqrt(delta);
            if (!delta) 
            {
                if (x%2) 
                {
                    cout<<0<<" ";
                    continue;
                }
                int X=x/2;
                cout<<1ll*D[X]*(D[X]-1)/2<<" ";
            }
            else
            {
                if ((-x+delta)%2 || (-x-delta)%2)
                {
                    cout<<0<<" ";
                    continue;
                }
                int x1=(-x+delta)/(-2);
                int x2=(-x-delta)/(-2);
                cout<<1ll*D[x1]*D[x2]<<" "; 
            }
        }
        cout<<"\n";
        D.clear();
    }
}
