#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 30004
string s;
int n;
struct node{
    int op=0,cl=0;
};
node Merge(node l,node r)
{
    node answer;
    int Min=min(l.op,r.cl);
    answer.op=l.op+r.op-Min;
    answer.cl=l.cl+r.cl-Min;
    return answer;
}
struct Segment_Tree{
    vector<node> t;
    void init(int SZ)
    {
        t.resize(SZ*4);
    }
    void build(int id,int l,int r)
    {
        if (l==r) 
        {
            if (s[l] == '(') t[id]={1,0};
            else t[id]={0,1};
            return;
        }
        int m=l+r >> 1;
        build(id << 1,l,m);
        build(id << 1 | 1,m+1,r);
        t[id]=Merge(t[id << 1],t[id << 1 | 1]);
    }
    void update(int id,int l,int r,int p)
    {
        if (r<p || l>p) return;
        if (l==r)
        {
            swap(t[id].cl,t[id].op);
            return;
        }
        int m=l+r >> 1;
        update(id << 1,l,m,p);
        update(id << 1 | 1,m+1,r,p);
        t[id] = Merge(t[id << 1],t[id << 1 | 1]);
    }
} ST;
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    for (int ntest=1;ntest<=10;ntest++)
    {
        cout<<"Test "<<ntest<<":\n";
        cin>>n>>s;
        s=" "+s;
        ST.init(n);
        ST.build(1,1,n);
        int q; cin>>q;
        while (q--)
        {
            int type; cin>>type;
            if (type) 
                ST.update(1,1,n,type);
            else
            {
                if (!ST.t[1].cl && !ST.t[1].op) cout<<"YES\n";
                else cout<<"NO\n";
            }
        }
    }
}
