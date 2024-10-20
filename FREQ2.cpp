#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define pii pair<int,int>
const int BLOCK_SZ=502;
#define maxn 100005
int n,q,a[maxn],res,z[maxn],fre[maxn],ans[maxn];
struct query{
    int l,r,id;
    friend bool operator<(const query A,const query B)
    {
        if (A.l / BLOCK_SZ != B.l / BLOCK_SZ)
            return A.l / BLOCK_SZ < B.l / BLOCK_SZ;
        return A.r < B.r;
    }
} Q[maxn];
inline void add(int x)
{
    z[fre[x]]--;
    fre[x]++;
    z[fre[x]]++;
    if (res < fre[x]) res=fre[x];
}
inline void rem(int x)
{
    z[fre[x]]--;
    fre[x]--;
    z[fre[x]]++;
    if (z[res]==0) res--;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,q)
    {
        cin>>Q[i].l>>Q[i].r;
        Q[i].l++, Q[i].r++;
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
