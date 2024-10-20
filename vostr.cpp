#include<iostream>
#include<vector>
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define pii pair<int,int>
const int MOD=1e9+7,base=31;
#define maxn 1000006
char s[maxn],t[maxn];
int n,p[maxn],q,HS[maxn],HT[maxn];
int getHashS(int l,int r)
{
    return (HS[r] - 1ll*HS[l-1] * p[r-l+1] + 1ll*MOD*MOD)%MOD;
}
int getHashT(int l,int r)
{
    return (HT[r] - 1ll*HT[l-1] * p[r-l+1] + 1ll*MOD*MOD)%MOD;
}
inline char Query(int l,int r,int u,int v)
{
    int len=std::min(r-l,v-u) + 1;
    int low=0, high=len+1;
    while (high - low > 1)
    {
        int mid = low + high >> 1;
        if (getHashS(l,l+mid-1) == getHashT(u,u+mid-1)) low = mid;
        else high = mid;
    }
    int ans = low;
    if (l+ans-1 == r && u+ans-1 == v) return '=';
    if (l+ans-1 == r && u+ans-1 < v) return '<';
    if (l+ans-1 < r && u+ans-1 == v) return '>';
    if (s[l+ans] < t[u+ans]) return '<';
    if (s[l+ans] > t[u+ans]) return '>';
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    int l1,l2;
    scanf("%d %d",&l1,&l2);
    scanf("%s %s",s+1,t+1);
    p[0] = 1;
    int n= std::max(l1,l2);
    FOR(i,1,n) 
    {
        p[i] = (1ll * p[i-1] * base) % MOD;
        if (i<=l1) HS[i] = (1ll*HS[i-1] * base + s[i] - 'a' + 1) %MOD;
        if (i<=l2) HT[i] = (1ll*HT[i-1] * base + t[i] - 'a' + 1) %MOD;
    }
    scanf("%d",&q);
    while (q--)
    {
        int l,r,u,v;
        scanf("%d %d %d %d",&l,&r,&u,&v);
        printf("%c",Query(l,r,u,v));
    }
}
