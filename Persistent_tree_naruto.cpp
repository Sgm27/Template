#include<bits/stdc++.h>
using namespace std;
 
#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);
 
const int MAX = 2e5+10;
 
struct Node
{
    int left, right, val;
 
} tree[MAX*20];
 
int a[MAX], root[MAX], id;
map<int,int>mp,origin;
 
int update(int pos,int l,int r,int idx)
{
    if(idx > r || idx < l)
        return pos;
    else if(l == r)
    {
        tree[++id] = tree[pos];
        tree[id].val++;
        return id;
    }
 
    int mid = (l+r)>>1;
    tree[++id] = tree[pos], pos = id;
 
    tree[pos].left = update(tree[pos].left,l,mid,idx);
    tree[pos].right = update(tree[pos].right,mid+1,r,idx);
 
    tree[pos].val = tree[tree[pos].left].val + tree[tree[pos].right].val;
 
    return pos;
}
int kthElement(int a,int b,int l,int r,int k)
{
    if(l == r)
        return l;
 
    int mid = (l+r)>>1;
    int cnt = tree[tree[a].left].val - tree[tree[b].left].val;
    if(cnt >= k)
        return kthElement(tree[a].left,tree[b].left,l,mid,k);
    else
        return kthElement(tree[a].right,tree[b].right,mid+1,r,k-cnt);
}
void init(int n,int m)
{
    root[0] = tree[0].left = tree[0].right = tree[0].val = 0;
    for(int i=1; i<=n; i++)
    {
        // cerr<<"Pos a="<<mp[a[i]]<<"\n";
        root[i] = update(root[i-1], 1, m, mp[a[i]]);
    }
}
 
struct query
{
    int type, l, r, k, v;
}  q[MAX];
 
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
 
    FastRead
 
    int n,qq,m=0;
 
    cin >> n;
 
    set<int>ss;
    for(int i=1; i<=n; i++)
        cin >> a[i], ss.insert(a[i]);
    cin >> qq;
 
    for(int i=0; i<qq; i++)
    {
        cin >> q[i].type;
 
        if(q[i].type == 1)
        {
            cin >> q[i].v;
            ss.insert(q[i].v);
        }
        else if(q[i].type == 3)
            cin >> q[i].l >> q[i].r >> q[i].k;
    }
 
    for(auto i=ss.rbegin(); i!=ss.rend(); i++)
        mp[*i] = ++m, origin[m] = *i;
    // for (int i=1;i<=m;i++)  cerr<<origin[i]<<" "; cerr<<"\n";
    init(n,m);
    int cur = n+1;
    for(int i=0; i<qq; i++)
    {
        // cerr<<i<<" "<<cur<<"\n";
        if(q[i].type == 2)
            cur--;
        else if(q[i].type == 1)
        {
            // cerr<<q[i].v<<" ";
            // cerr<<"pos = "<<mp[q[i].v]<<"\n";

            root[cur] = update(root[cur-1], 1, m, mp[q[i].v]) , cur++;
        }
        else
        {
            // cout<<q[i].l<<" "<<q[i].r<<" "<<q[i].k<<"\n";
            // cout<<"ans="<<kthElement(root[q[i].r],root[q[i].l-1],1,m,q[i].k)<<"\n";
            cout << origin[kthElement(root[q[i].r],root[q[i].l-1],1,m,q[i].k)] << endl;
        }
    }
}