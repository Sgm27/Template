#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxbit 16
#define maxn 
int ans,n;
struct Node{
    Node* child[2];
    int count,exist;
    Node()
    {
        memset(child,0,sizeof(child));
        count = exist = 0;
    }
};
Node *root = new Node();
inline void Add(int val)
{
    Node *p = root;
    FOD(i,maxbit,0)
    {
        int id = (val >> i) & 1;
        if (p->child[id] == NULL) p->child[id] = new Node();
        if (id == 0 && p->child[1] != NULL) ans+=p->child[1]->count;
        p = p->child[id];
        p->count++;
    }
    p->exist++;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    while (n--)
    {
        int val; cin>>val;
        Add(val);
    }
    cout<<ans;
}
