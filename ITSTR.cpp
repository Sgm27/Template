#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
#define maxn 100005
const int MOD=1007050321;
int n,q,Pow[maxn];
string s;
struct node{
    int hash,len;
} t[maxn*4];
struct Fenwick{
    int t[maxn];
    void update(int x)
    {
        for (;x<=n;x+=x&-x) t[x]++;
    }
    int get(int x)
    {
        int ans=0;
        for (;x>0;x-=x&-x) ans+=t[x];
        return ans;
    }
} fw;
node Merge(node l,node r)
{
    node ans;
    ans.len=l.len+r.len;
    ans.hash=(l.hash*Pow[r.len]+r.hash)%MOD;
    return ans;
}
void build(int id,int l,int r)
{
    if (l==r) return t[id]={s[l]-'0',1} , void();
    int m=(l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id]=Merge(t[id*2],t[id*2+1]);
}
void update(int id,int l,int r,int p)
{
    if (r<p || l>p) return;
    if (l==r)
    {
        t[id]={0,0};
        return;
    }
    int m=(l+r)/2;
    update(id*2,l,m,p);
    update(id*2+1,m+1,r,p);
    t[id]=Merge(t[id*2],t[id*2+1]);
}
node get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return {0,0};
    if (l>=u && r<=v) return t[id];
    int m=(l+r)/2;
    node t1=get(id*2,l,m,u,v);
    node t2=get(id*2+1,m+1,r,u,v);
    return Merge(t1,t2);
}
int f(int x)
{
    return x-fw.get(x);
}
int new_pos(int p)
{
    int l=0,r=n;
    while (r-l>1)
    {
        int m=(l+r)/2;
        if ((f(m))>=p) r=m;
        else l=m;
    }
    return r;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    Pow[0]=1;
    FOR(i,1,maxn-5) Pow[i]=(Pow[i-1]*2)%MOD;
    cin>>s;
    n=s.length();
    s=" "+s;
    build(1,1,n);
    cin>>q;
    while (q--)
    {
        char type;
        int u,v;
        cin>>type;
        if (type=='?')
        {
            cin>>u>>v;
            int new_u=new_pos(u);
            int new_v=new_pos(v);
            cout<<get(1,1,n,new_u,new_v).hash<<"\n";
        }
        else 
        {
            int p; cin>>p;
            int new_p=new_pos(p);
            update(1,1,n,new_p);
            fw.update(new_p);
        }
    }
}
