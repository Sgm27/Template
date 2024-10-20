#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 100005
int n,k,a[maxn];
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
inline void compress(int a[])
{
    vector<int> v;
    for (int i=1;i<=n;i++) v.push_back(a[i]);
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    FOR(i,1,n)
        a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
} 
inline void process()
{
    Fenwick fw(n);
    int Left,Right=n,count_inv=0,answer=0;
    FOD(i,n,1)
    {
        fw.update(a[i],1);
        count_inv += fw.get(a[i]-1);
        if (count_inv >= k)
        {
            Left=i;
            break;
        }
    }
    while (Left >= 1)
    {
        while (count_inv>=k) 
        {
            answer += Left;
            int inv_in_Right=fw.get(n) - fw.get(a[Right]);
            count_inv -= inv_in_Right;
            fw.update(a[Right],-1);
            Right--;
        }   
        if (Left == 1) break;
        while (Left>1 && count_inv<k)
        {
            Left--;
            int inv_in_Left=fw.get(a[Left]-1);
            count_inv += inv_in_Left;
            fw.update(a[Left],1);
        }
    }
    cout<<answer<<"\n";
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>k;
    FOR(i,1,n) cin>>a[i];
    if (!k) 
        return cout<<n*(n+1)/2<<"\n", 0;
    compress(a);
    process();
}
