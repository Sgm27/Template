#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
#define maxn 

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        int n;
        cin>>n;
        vector<int> a(n+1);
        FOR(i,1,n) cin>>a[i];
        int nim=a[1],Max=a[1];
        FOR(i,2,n) nim^=a[i], Max=max(Max,a[i]);
        if ((!nim && Max<=1) || (nim && Max>1)) cout<<"1\n"; 
        else cout<<"-1\n";
    }
}
