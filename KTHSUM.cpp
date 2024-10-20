#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 100005
int n,a[maxn],k;
int N;
vector<int> com;
struct Fenwick{
    vector<int> t;
    int n;
    void init(int sz)
    {
        n=sz;
        t.assign(n+1,0);
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
} fw;
int find_pos(int val)
{
    return lower_bound(com.begin(),com.end(),val) - com.begin() + 1;
}
int f(int x)
{
    fw.init(N);
    int curSum = 0, ans = 0;
    FOR(i,1,n)
    {
        fw.update(find_pos(curSum),1);
        curSum += a[i];
        int Pos = find_pos(curSum - x);
        if (com[Pos - 1] != curSum - x) Pos--;
        if (Pos) ans += fw.get(Pos);
    }
    return ans;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int curSum = 0;
    com.push_back(curSum);
    cin>>n>>k;
    FOR(i,1,n)
    {
        cin>>a[i]; 
        curSum += a[i];
        com.push_back(curSum);
    }
    sort(com.begin(),com.end());
    com.resize(unique(com.begin(),com.end()) - com.begin());
    N = com.size();
    int l = -1e14 , r = 1e14+1;
    while (r-l>1)
    {
        int m = l+r >> 1;
        if (f(m) >= k) l = m;
        else r = m; 
    }
    cout<<l;
}
