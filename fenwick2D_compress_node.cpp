#include <bits/stdc++.h>
#define LOG 20
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define FIRST_BIT(mask) __builtin_ctz((mask)&(-mask))
#define ERASE_BIT(mask) (mask)^((mask)&(-mask))
#define left _left
#define right _right
#define int long long
using namespace std;
const int INF=1e18;
const int iat=2e5+9;
const int mod=1e9+7;
const int MAX=15e5;
void fast_IO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
}

int n;
struct query{
    int type,x1,y1,x2,y2,val;
} Q[iat];
pair <int,int> a[iat];
struct Fenwick2d
{
    vector <vector<int>> node,bit;
    int sz;
    void init(int n)
    {
        sz=n;
        node.resize(n+1);
        bit.resize(n+1);
    }
    void compressNode()
    {
        for(int i=1; i<=sz; i++)
        {
            sort(node[i].begin(),node[i].end());
            node[i].erase(unique(node[i].begin(),node[i].end()),node[i].end());
        }k
    }
    void fakeUpdate(int x, int y)
    {
        for(; x<=sz; x+=x&-x)node[x].push_back(y);
    }
    void fakeGet(int x, int y)
    {
        for(; x>0; x-=x&-x)node[x].push_back(y);
    }
    void update(int x, int yy, int val)
    {
        for(; x<=sz; x+=x&-x)
        {
            for(int y=lower_bound(node[x].begin(),node[x].end(),yy)-node[x].begin()+1; y<=node[x].size(); y+=y&-y)
            {
                bit[x][y-1]+=val; 
            }
        }
    }
    int get(int x, int yy)
    {
        int res=0;
        for(; x>0; x-=x&-x)
        {
            for(int y=lower_bound(node[x].begin(),node[x].end(),yy)-node[x].begin()+1; y>0; y-=y&-y)
            {
                res+=bit[x][y-1];
            }
        }
        return res;
    }
}tree;
signed main()
{
    fast_IO();
    cin>>n;
    tree.init(n);
    int q; cin>>q;
    for (int i=1;i<=q;i++)
    {
        string s; cin>>s;
        if (s=="S") 
        {
            Q[i].type=-1;
            cin>>Q[i].x1>>Q[i].y1>>Q[i].val;
        }
        else
        {
            Q[i].type=1;
            cin>>Q[i].x1>>Q[i].y1>>Q[i].x2>>Q[i].y2;
        }
    }
    for (int i=1;i<=q;i++)
    {
        if (Q[i].type==1) 
        {
            tree.fakeGet(Q[i].x1-1,Q[i].y1-1);
            tree.fakeGet(Q[i].x2,Q[i].y2);
            tree.fakeGet(Q[i].x2,Q[i].y1-1);
            tree.fakeGet(Q[i].x1-1,Q[i].y2);
        }
        else
        {
            tree.fakeUpdate(Q[i].x1,Q[i].y1);
        }
    }
    tree.compressNode();
    for (int i=1;i<=q;i++)
    {
        if (Q[i].type==1)
        {
            cout<<tree.get(Q[i].x2,Q[i].y2)-tree.get(Q[i].x1-1,Q[i].y2)-tree.get(Q[i].x2,Q[i].y1-1)+tree.get(Q[i].x1-1,Q[i].y1-1)<<"\n";
        }
        else
        {
            tree.update(Q[i].x1,Q[i].y1,Q[i].val);
        }
    }
}
