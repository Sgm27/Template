#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18,base = 31;
#define maxn 100005
int p[maxn];
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
} HS,HT;
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>s>>t;
    string realS = s, realT=t;
    int l1=s.length() , l2=t.length();
    s=" " + s , t=" " + t; 
    HS.init(s) , HT.init(t);
    p[0] = 1;
    FOR(i,1,max(l1,l2)) p[i] = (p[i-1] * base) %MOD;
    int ans = -1;
    FOD(i,min(l1,l2),1)
        if (HS.getHash(l1-i+1,l1) == HT.getHash(1,i)) 
        {
            ans = i;
            break;
        }
    if (ans == -1) cout<<realS<<realT;
    else
    {
        cout<<realS;
        string subT=realT.substr(ans,l2-ans+1);
        cout<<subT;
    }
}
