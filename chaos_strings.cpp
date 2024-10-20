#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 100005
int n;
vector<string> com;
struct Word{
    string T,N;
    friend bool operator<(const Word a,const Word b)
    {
        if (a.T != b.T) return a.T < b.T;
        if (a.N != b.N) return a.N < a.N;
    }
} a[maxn];
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
int find_pos(string val)
{
    return lower_bound(com.begin(),com.end(),val) - com.begin() + 1;
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
        cin>>a[i].T;
        a[i].N = a[i].T;
        reverse(a[i].N.begin(),a[i].N.end());
        com.push_back(a[i].N);
    }
    sort(com.begin(),com.end());
    com.resize(unique(com.begin(),com.end()) - com.begin());
    sort(a+1,a+1+n);
    int ans = 0;
    Fenwick fw(n);
    FOD(i,n,1)
    {
        int pos = find_pos(a[i].N);
        ans += fw.get(pos - 1);
        fw.update(pos,1);
    }
    cout<<ans;
}
