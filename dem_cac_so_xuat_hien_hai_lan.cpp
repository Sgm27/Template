#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define pii pair<int,int>
#define maxn 500005
int n,q,a[maxn],fre[maxn],ans[maxn],cnt[maxn],res,BLOCK_SZ;
struct query{
    int l,r,id;
    friend bool operator<(const query A,const query B)
    {
        if (A.l / BLOCK_SZ != B.l / BLOCK_SZ)
            return A.l / BLOCK_SZ < B.l / BLOCK_SZ;
        return A.r < B.r;
    }
} Q[maxn];
inline void add(int val)
{
    fre[val]++;
    if (fre[val] == 2) res++;
    if (fre[val] == 3) res--;
}
inline void remove(int val)
{
    fre[val]--;
    if (fre[val] == 2) res++;
    if (fre[val] == 1) res--;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    vector<int> com;
    cin>>n>>q;
    BLOCK_SZ = sqrt(n) + 1;
    FOR(i,1,n) cin>>a[i], com.push_back(a[i]);
    sort(com.begin(),com.end());
    com.resize(unique(com.begin(),com.end()) - com.begin());
    FOR(i,1,n) 
        a[i] = lower_bound(com.begin(),com.end(),a[i]) - com.begin() + 1;
    FOR(i,1,q)
    {
        cin>>Q[i].l>>Q[i].r;
        Q[i].id = i;
    }
    sort(Q+1,Q+1+q);
    int curL=1,curR=0;
    FOR(i,1,q)
    {
        int left=Q[i].l;
        int right=Q[i].r;
        while (curR < right) add(a[++curR]);
        while (curR > right) remove(a[curR--]);
        while (curL < left) remove(a[curL++]);
        while (curL > left) add(a[--curL]);
        ans[Q[i].id] = res;
    }
    FOR(i,1,q) cout<<ans[i]<<"\n";
}
