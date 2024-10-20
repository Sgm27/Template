#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
const int BLOCK_SZ=502;
#define maxn 30005
#define maxv 1000006
int n,q,a[maxn],res,cnt[maxv],ans[maxv];
struct query{
    int l,r,id;
    friend bool operator<(const query A,const query B)
    {
        if (A.l / BLOCK_SZ != B.l / BLOCK_SZ)
            return A.l / BLOCK_SZ < B.l / BLOCK_SZ;
        return A.r < B.r;
    }
} Q[maxv];
inline void add(int x)
{
    cnt[x]++;
    if (cnt[x] == 1) res++;
}
inline void rem(int x)
{
    cnt[x]--;
    if (cnt[x] == 0) res--;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    cin>>q;
    FOR(i,1,q)
    {
        cin>>Q[i].l>>Q[i].r;
        Q[i].id = i;
    }
    sort(Q+1,Q+1+q);
    int curL=1, curR=0;
    FOR(i,1,q)
    {
        int left=Q[i].l;
        int right=Q[i].r;
        while (curR < right) add(a[++curR]);
        while (curR > right) rem(a[curR--]);
        while (curL < left) rem(a[curL++]);
        while (curL > left) add(a[--curL]);
        ans[Q[i].id] = res;
    }
    FOR(i,1,q) cout<<ans[i]<<"\n";
}
