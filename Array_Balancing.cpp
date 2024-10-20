#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define pii pair<int,int>
using ll = long long;
#define maxn 50
int n,a[maxn],b[maxn];
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n;
        FOR(i,1,n) cin>>a[i];
        FOR(i,1,n) cin>>b[i];
        ll ans=0;
        for (int i=2;i<=n;i++)
            if (abs(a[i]-a[i-1])+abs(b[i]-b[i-1])>abs(b[i]-a[i-1])+abs(a[i]-b[i-1]))
            {
                ans+=abs(b[i]-a[i-1])+abs(a[i]-b[i-1]);
                swap(a[i],b[i]);
            }
            else ans+=abs(a[i]-a[i-1])+abs(b[i]-b[i-1]);
        cout<<ans<<"\n";
    }    
}
