#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
const int base=31;
#define maxn 1000006
int n,m,p[maxn],ht,hs[maxn];
string s,t;
stack<char> st;
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    p[0]=1;
    FOR(i,1,maxn-6) p[i]=(p[i-1]*base)%MOD;
    cin>>s>>t;
    n=s.length(), m=t.length();
    s=" "+s, t=" "+t;
    FOR(i,1,m)
        ht=(ht*base+(t[i]-'a'+1))%MOD;
    int idx=0;
    FOR(i,1,n)
    {
        st.push(s[i]);
        idx++;
        hs[idx]=(hs[idx-1]*base+(s[i]-'a'+1))%MOD;
        if (st.size()>=m)
        {
            int hash_subS=(hs[idx]-hs[idx-m]*p[m]+MOD*MOD)%MOD;
            if (hash_subS==ht) 
            {
                idx-=m;
                FOR(k,1,m) st.pop();
            }
        }
    }
    string ans="";
    while (!st.empty()) ans+=st.top(), st.pop();
    reverse(ans.begin(),ans.end());
    cout<<ans;
}
