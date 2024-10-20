#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 500005
int X,Y,n;
pii a[maxn];
struct Fenwick{
    vector<int> t;
    int n;
    Fenwick(int sz)
    {
        n=sz;
        t.resize(n+1);
    }
    void update(int x,int val)
    {
        for (;x<=n;x+=x&-x) t[x]+=val;
    }
    int get(int x)
    {
        int ans=0;
        for (;x>0;x-=x&-x) ans+=t[x];
        return ans;
    }
};
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc,nTest = 0; cin>>tc;
    while (++nTest <= tc)
    {
        cout<<"Test case "<<nTest<<": ";
        cin>>X>>Y>>n;
        FOR(i,1,n) cin>>a[i].first>>a[i].second;
        sort(a+1,a+1+n);
        vector<int> wait;
        Fenwick fw(Y+5);
        int ans = 0;
        a[0] = {-1,-1};
        FOR(i,1,n)
        {
            if (a[i].first != a[i-1].first) 
            {
                for (int x : wait)
                    fw.update(x,1);
                wait.clear();
                wait.push_back(a[i].second);
            }
            else
                wait.push_back(a[i].second);
            ans += fw.get(Y) - fw.get(a[i].second);
        }
        cout<<ans<<"\n";
    }
}
