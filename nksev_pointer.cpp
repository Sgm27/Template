#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1337377,INF=9e18;
#define maxn 300005
string s;
int q,dp[maxn];
struct Node{
    Node* child[26];
    int count,exist;
    Node()
    {
        memset(child,0,sizeof(child));
        count = exist = 0;
    }
};
Node *root = new Node();
void add(string s)
{
    Node *p=root;
    for (char c : s)
    {
        int id = c - 'a';
        if (p -> child[id] == NULL) p -> child[id] = new Node();
        p = p->child[id];
        p -> count++;
    }
    p->exist++;
}
void solve()
{
    int len = s.length();
    s = " " + s;
    dp[0] = 1;
    for (int i=0;i<len;i++)
        if (dp[i])
        {
            Node *p=root;
            for (int j=i+1;j<=len;j++)
            {
                int id = s[j] - 'a';
                if (p->child[id] == NULL) break;
                p = p->child[id];
                if (p->exist != 0) (dp[j] += dp[i]) %= MOD; 
            }
        }
    cout<<dp[len];
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>s>>q;
    while (q--)
    {
        string t; cin>>t;
        add(t);
    }
    solve();
}
