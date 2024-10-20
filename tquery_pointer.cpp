#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define maxbit 30
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 
unordered_map<int,int> have;
struct Node{
    Node* child[2];
    int count,exist,val,sum;
    Node()
    {
        memset(child,0,sizeof(child));
        count = exist = val = sum = 0;
    }
};
Node *root = new Node();
void Add(int val)
{
    Node *p = root;
    FOD(i,maxbit,0)
    {
        int id = (val >> i) & 1;
        if (p -> child[id] == NULL) p -> child[id] = new Node();
        p = p->child[id];
        p->count++;
        p->sum += val;
    }
    p->val = val;
    p->exist++;
}
void Del(int val)
{
    Node *p = root;
    FOD(i,maxbit,0)
    {
        int id = (val >> i) & 1;
        p -> child[id] -> count--;
        if (p ->child[id]->count == 0)
        {
            p->child[id]->exist--;
            p->child[id] = NULL;
            return;
        }
        p = p->child[id];
        p -> sum -= val;
    }
    p->exist--;
    if (p->exist == 0) p->val = 0;
}
int getSum(int k)
{
    if (k<=0) return 0;
    Node *p = root;
    int sum = 0;
    FOD(i,maxbit,0)
    {
        int id = (k >> i) & 1;
        if (p -> child[0] != NULL && id == 1) sum += p->child[0]->sum;
        if (p -> child[id] != NULL) p = p->child[id];
        else break;
    } 
    return sum + p->exist * p->val;
}
int findKth(int k)
{
    Node *p = root;
    FOD(i,maxbit,0)
    {
        if (p->child[0] != NULL && p->child[0]->count >= k) 
            p = p->child[0];
        else
        {
            if (p->child[0] != NULL) k -= p->child[0]->count;
            p = p->child[1];
        } 
    }
    return p->val;
}
int maxXor(int val)
{
    Node *p = root;
    FOD(i,maxbit,0)
    {
        int id = (val >> i) & 1;
        if (p->child[id^1] != NULL) p = p->child[id^1];
        else 
            p = p->child[id];
    }
    return p->val ^ val;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int q; cin>>q;
    while (q--)
    {
        int type; cin>>type;
        if (type == 1) 
        {
            int val; cin>>val;
            have[val]++;
            Add(val);
        }
        else
        if (type == 2)
        {
            int val; cin>>val;
            if (have[val])
            {
                have[val]--;
                Del(val);
            }
        }
        else
        if (type == 3)
        {
            int l,r;
            cin>>l>>r;
            cout<<getSum(r) - getSum(l-1)<<"\n";
        }
        else
        if (type == 4)
        {
            int k; cin>>k;
            cout<<findKth(k)<<"\n";
        }
        else
        {
            int val; cin>>val;
            cout<<maxXor(val)<<"\n";
        }
    }
}
