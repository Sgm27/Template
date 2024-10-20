#ifdef DS
    #include "debug.h"
#else 
    #include<bits/stdc++.h>
    #define deb(...) 
#endif
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define NALL(x) x.begin()+1,x.end()
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define vi vector<int>
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18,base = 31;
#define maxn 1000006
int p[maxn];
struct Hashing
{   
    vi hash;
    int sz;
    Hashing(string s)
    {
        sz = s.length();
        hash.resize(sz+1);
        s = " " + s;
        FOR(i,1,sz)
            hash[i] = (hash[i-1] * base + s[i] - 'a' + 1) %MOD; 
    }
    int getHash(int l,int r)
    {
        return (hash[r] - hash[l-1] * p[r-l+1] + MOD*MOD) %MOD; 
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
    FOR(i,1,maxn - 1)
        p[i] = (p[i-1] * base) %MOD;
    string s; cin>>s;
    Hashing HS(s);
    s = " " + s;
    vi ans;
    FOR(i,1,HS.sz)
    {
        int cur_hash = HS.getHash(1,i);
        int j = i;
        bool check = true;
        for (j = i;j <= HS.sz; j += i)
        {
            if (cur_hash != HS.getHash(j-i+1, j)) 
            {
                check = false;
                break;
            }
        }
        j -= i;
        if (check)
        {
            if (j != HS.sz)
            {
                if (HS.getHash(j+1, HS.sz) == HS.getHash(1,HS.sz - j))
                    ans.push_back(i);
            }
            else
                ans.push_back(i);
        }
    }
    for (int x : ans)
        cout<<x<<" ";
}
