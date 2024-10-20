#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 10005
int n,q,a[maxn],N;

struct Node{
    Node* child[2];
    int count,exist;
    Node()
    {
        memset(child,0,sizeof(child));
        count = exist = 0;
    }
};
Node *root=new Node();
void Add(int a[],int SZ)
{
    Node *p=root;
    for (int i=1;i<=SZ;i++)
    {
        int id = a[i];
        if (p->child[id] == NULL) p->child[id]=new Node();
        p = p->child[id];
        p -> count++;
    }
    p->exist++;
}
int Query(int a[],int SZ)
{
    int answer=0;
    Node *p=root;
    for (int i=1;i<=SZ;i++)
    {
        int id=a[i];
        if (p -> child[id] == NULL) return answer;
        p = p -> child[id];
        answer += p->exist;
    }
    return answer + p->count - p->exist;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    while (n--)
    {
        cin>>N;
        FOR(i,1,N) cin>>a[i];
        Add(a,N);
    }
    while (q--)
    {
        cin>>N;
        FOR(i,1,N) cin>>a[i];
        cout<<Query(a,N)<<"\n";
    }
}
