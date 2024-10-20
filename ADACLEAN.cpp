#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18,base1 = 31,base2 = 47;
#define maxn 100005
int n,p1[maxn],p2[maxn],k;
string s;
map<pair<int,int>,int> D;
struct Hashing{
    vector<int> hash1,hash2;
    int SZ;
    Hashing (string cur)
    {
        SZ = cur.size();
        hash1.resize(SZ+1);
        hash2.resize(SZ+1);
        hash1[0] = hash2[0] = 0;
        FOR(i,1,n) 
        {
            hash1[i] = (hash1[i-1]*base1 + cur[i] - 'a' + 1) % MOD; 
            hash2[i] = (hash2[i-1]*base2 + cur[i] - 'a' + 1) % MOD;
        }
    }
    int getHash1(int l,int r)
    {
        return (hash1[r] - hash1[l-1] * p1[r-l+1] + MOD*MOD) % MOD;
    }
    int getHash2(int l,int r)
    {
        return (hash2[r] - hash2[l-1] * p2[r-l+1] + MOD*MOD) % MOD;
    }
};
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    p1[0] = p2[0] = 1;
    FOR(i,1,maxn-5) 
    {
        p1[i] = (p1[i-1] * base1) %MOD;
        p2[i] = (p2[i-1] * base2) %MOD;
    }
    while (tc--)
    {
        D.clear();
        cin>>n>>k;   
        cin>>s;
        s=" "+s;
        Hashing HS(s);
        FOR(i,k,n)
            D[{HS.getHash1(i-k+1,i),HS.getHash2(i-k+1,i)}] = 1;
        cout<<D.size()<<"\n";
    }
}
