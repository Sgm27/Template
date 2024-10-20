#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
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
        int sum=0,nx_sum;
        vector<int> a(n+1);
        FOR(i,1,n)
        {
            nx_sum=((sum+a[i-1])/(i+1)+1)*(i+1);
            a[i]=nx_sum-sum;
            cout<<a[i]<<" ";
            sum=nx_sum;
        }   
        cout<<"\n";
    }
}
