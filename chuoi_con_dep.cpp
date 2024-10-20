#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 15005   
int k,d[255],n,prefix[maxn];
string s;

struct Hashing
{
    const int base1=97,base2=2701;
    int n;
    vector<int> p1,p2,hs1,hs2;
    Hashing() {}
    Hashing(string s,int len)
    {
        n=len;
        p1.resize(n+5); p2.resize(n+5);
        hs1.resize(n+5); hs2.resize(n+5);
        p1[0]=p2[0]=1, hs1[0]=hs2[0]=0;
        FOR(i,1,n) 
        {
            p1[i]=(p1[i-1]*base1)%MOD;
            p2[i]=(p2[i-1]*base2)%MOD;
        }
        FOR(i,1,n) 
        {
            hs1[i]=(hs1[i-1]*base1+(s[i]-'a'+1))%MOD;
            hs2[i]=(hs2[i-1]*base2+(s[i]-'a'+1))%MOD;
        }
    }
    int get_hash1(int l,int r)
    {
        return (hs1[r]-hs1[l-1]*p1[r-l+1]+MOD*MOD)%MOD;
    }
    int get_hash2(int l,int r)
    {
        return (hs2[r]-hs2[l-1]*p2[r-l+1]+MOD*MOD)%MOD;
    }
};
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>s;
    int n=s.length();
    s=" "+s;
    string t; cin>>t;
    cin>>k;
    FOR(i,0,25) 
        if (t[i]=='1') d[97+i]=1;
    FOR(i,1,n)
        prefix[i]=prefix[i-1]+!d[s[i]];
    Hashing hashS(s,n);
    unordered_map<int,int> D1,D2;
    int ans=0;
    FOR(i,1,n)
        FOR(j,i,n)
            if (prefix[j]-prefix[i-1]<=k && !D1[hashS.get_hash1(i,j)] && !D2[hashS.get_hash2(i,j)]) 
            {
                ans++;
                D1[hashS.get_hash1(i,j)]=1;
                D2[hashS.get_hash2(i,j)]=1;
                // cout<<i<<" "<<j<<"\n";
            }
    cout<<ans;
}
