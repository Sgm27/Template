#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18,base = 31;
#define maxn 1000006
string s;
int n,p[maxn];
struct Hashing{
    vector<int> hash;
    int SZ;
    Hashing (string cur)
    {
        SZ = cur.size();
        hash.resize(SZ+1);
        hash[0]=0;
        FOR(i,1,n) 
            hash[i] = (hash[i-1]*base + cur[i] - 'a' + 1) % MOD; 
    }
    int getHash(int l,int r)
    {
        return (hash[r] - hash[l-1] * p[r-l+1] + MOD*MOD) % MOD;
    }
};
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    p[0] = 1;
    FOR(i,1,maxn-6) 
        p[i] = (p[i-1] * base) % MOD;
    int tc,ntest=0; cin>>tc;
    while (tc-- && ++ntest)
    {
        cout<<"Case "<<ntest<<": ";
        cin>>s;
        n=s.length();
        s=" "+s;
        int answer=0;
        Hashing HS(s);
        FOR(i,1,n-1)
            if (HS.getHash(1,i) == HS.getHash(n-i+1,n)) answer++;
        cout<<answer<<"\n";
    }
}
