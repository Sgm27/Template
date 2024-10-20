#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18,base=31;
#define maxn 55
int n,h[maxn],p[maxn];
string s;
unordered_map<int,int> D;
void build_pow()
{
    p[0]=1;
    FOR(i,1,maxn-1) p[i]=(p[i-1]*base)%MOD;
}
int get_hash(string t)
{
    int ans=0;
    for (char c : t)
        ans=(ans*base+c-'a'+1)%MOD;
    return ans;
}
inline void process()
{
    stack<int> 
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    build_pow();
    while (cin>>n)
    {
        D.clear();
        if (n==0) return 0;
        cin>>s;
        FOR(i,1,n)
        {
            string t; cin>>t;
            D[get_hash(t)]=1;
        }   
        process();
    }
}
