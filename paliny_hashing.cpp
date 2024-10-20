#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18,base=31;
#define maxn 50004
int p[maxn],n;
string s,t;
struct Hashing{
    vector<int> hash;
    int SZ;
    void init(string s)
    {
        SZ=s.size();
        hash.resize(SZ+1);
        FOR(i,1,SZ) 
            hash[i]=(hash[i-1]*base + s[i] - 'a' + 1)%MOD;
    }
    int getHash(int l,int r)
    {
        return (hash[r] - hash[l-1] * p[r-l+1] + MOD*MOD)%MOD;
    }
} HS,HR;
bool f(int x)
{
    //  n-(i+x-1)+1 -> n-(i+x-1)+1+x-1
    FOR(i,1,n-x+1)
        if (HS.getHash(i,i+x-1) == HR.getHash(n-(i+x-1)+1,n-(i+x-1)+x)) return true;
    return false;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    cin>>s;
    p[0] = 1;
    FOR(i,1,n) p[i] = (p[i-1] * base) %MOD;
    t=s;
    reverse(t.begin(),t.end());
    s=" " + s, t=" " + t;
    HS.init(s), HR.init(t);
    int ans = 0;
    // chat nhi phan do dai le
    int l = 1 , r = n - (n%2==0) + 1;
    while (r-l>2)
    {
        int m = l+r >> 1;
        m += (m%2 == 0);
        if (f(m)) l=m;
        else r=m;
    }
    ans = max(ans,l);
    // chat nhi phan do dai chan
    l = 0 , r = n - (n%2) + 1;
    while (r-l>2)
    {
        int m = l+r >> 1;
        m += (m%2);
        if (f(m)) l=m;
        else r=m;
    }
    ans = max(ans,l);
    cout<<ans;
}
