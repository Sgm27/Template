#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
#define pi M_PI
const int MOD=1e9+7,INF=9e18;
#define maxn 100005
int n;
struct data{
    int r,h,V;
} a[maxn];
int dp[maxn],answer;
vector<int> com;
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
        for (;x<=n;x+=x&-x) t[x]=max(t[x],val);
    }
    int get(int x)
    {
        int ans=0;
        for (;x>0;x-=x&-x) ans=max(ans,t[x]);
        return ans;
    }
};
int find_pos(int x)
{
    return lower_bound(com.begin(),com.end(),x) - com.begin() + 1;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n) 
    {
        cin>>a[i].r>>a[i].h;
        a[i].V=a[i].r*a[i].r*a[i].h;
        com.push_back(a[i].V);
    }
    sort(com.begin(),com.end());
    com.resize(unique(com.begin(),com.end()) - com.begin());
    Fenwick fw(com.size() + 5);
    FOR(i,1,n)
    {
        int Pos = find_pos(a[i].V);
        dp[i]=a[i].V + fw.get(Pos-1);
        answer = max(answer,dp[i]);
        fw.update(Pos,dp[i]);
    }
    cout<<fixed<<setprecision(8)<<(long double)(answer * pi);
}
