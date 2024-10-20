#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18,base = 31;
#define maxn 100005
string s,t;
int n,p[maxn];
struct Hashing{
    int n;
    vector<int> hash;
    Hashing(string cur)
    {
        n=cur.length();
        hash.resize(n+1);
        FOR(i,1,n) 
            hash[i] = (hash[i-1]*base + cur[i] - 'A' + 1) % MOD;
    }
    int getHash(int l,int r)
    {
        return (hash[r] - hash[l-1]*p[r-l+1] + MOD*MOD)%MOD;
    }
};
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>s>>t;
    t=" "+t;
    n=s.length();
    s =" " + s + s;
    int answer=0;
    p[0] = 1;
    FOR(i,1,n) 
        p[i] = (p[i-1]*base)%MOD;
    Hashing HS(s), HT(t);
    FOR(i,1,n)
    {
        int l=i, r=i+n;
        while (r-l > 1)
        {
            int mid = l+r >> 1;
            if (HS.getHash(i,mid) == HT.getHash(1,mid-i+1)) l=mid;
            else r=mid;
        }
        if (l-i+1 == n) answer += n;
        else
        {
            int start = l-i+1+2;
            if (HS.getHash(l+2,i+n-1) == HT.getHash(start,n)) answer++;
        }
    }
    cout<<answer;
}   
