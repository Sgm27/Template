#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 100005
int n,a[maxn];
int lmin[maxn],rmin[maxn],lmax[maxn],rmax[maxn];
stack<int> st1,st2;
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n) 
    {
        while (st1.size() && a[st1.top()] >= a[i]) st1.pop();
        while (st2.size() && a[st2.top()] <= a[i]) st2.pop();
        if (st1.size()) lmin[i]=st1.top()+1;
        else lmin[i]=1;
        if (st2.size()) lmax[i]=st2.top()+1;
        else lmax[i]=1;
        st1.push(i);
        st2.push(i);
    }
    while (st1.size()) st1.pop();
    while (st2.size()) st2.pop();
    FOD(i,n,1)
    {
        while (st1.size() && a[st1.top()] > a[i]) st1.pop();
        while (st2.size() && a[st2.top()] < a[i]) st2.pop();
        if (st1.size()) rmin[i]=st1.top()-1;
        else rmin[i]=n;
        if (st2.size()) rmax[i]=st2.top()-1;
        else rmax[i]=n;
        st1.push(i);
        st2.push(i);
    }
    int ans=0;
    FOR(i,1,n)
    {
        ans+=a[i]*(i-lmax[i]+1)*(rmax[i]-i+1);
        ans-=a[i]*(i-lmin[i]+1)*(rmin[i]-i+1);
        cout<<(i-lmin[i]+1)<<" "<<(rmin[i]-i+1)<<" "<<(i-lmax[i]+1)<<" "<<(rmax[i]-i+1)<<"\n";
        // cout<<ans<<"\n";
    }
    cout<<ans;
}
