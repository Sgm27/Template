#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 200005
string s;
int n,q,p[maxn];
struct node{
    int hash,len;
} t[maxn*4];
struct Fenwick{
    int f[maxn];
    void update(int x)
    {
        for (;x<=n;x+=x&-x) f[x]++;
    }
    int get(int x)
    {
        int ans=0;
        for (;x>0;x-=x&-x) ans+=f[x];
        return ans;
    }
} fw;
node Merge(node l,node r)
{
    node res;
    res.len=l.len+r.len;
    res.hash=(l.hash*p[r.len]+r.hash)%MOD;
    return res;
}
void build(int id,int l,int r)
{
    if (l==r) return t[id]={s[l]-'0',1}, void();
    int m=(l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id]=Merge(t[id*2],t[id*2+1]);
}
void update(int id,int l,int r,int p)
{
    if (r<p || l>p) return;
    if (l==r)
        return t[id]={0,0}, void();
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
    return Merge(get(id*2,l,m,u,v),get(id*2+1,m+1,r,u,v));
}
int f(int x)
{
    return x-fw.get(x);
}
int find_new_pos(int p)
{
    int l=0,r=n;
    while (r-l>1)
    {
        int m=(l+r)/2;
        if (f(m)>=p) r=m;
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
    cin>>s;
    n=s.length(); s=" "+s;
    p[0]=1;
    FOR(i,1,maxn-5) p[i]=(p[i-1]*2)%MOD;
    build(1,1,n);
    cin>>q;
    while (q--)
    {
        string type;
        cin>>type;
        if (type=="?")
        {
            int l,h,m;
            cin>>l>>h>>m;
            int new_l=find_new_pos(l);
            int new_lm=find_new_pos(l+m-1);
            int new_h=find_new_pos(h);
            int new_hm=find_new_pos(h+m-1);
            if (get(1,1,n,new_l,new_lm).hash==get(1,1,n,new_h,new_hm).hash) 
                cout<<"YES\n"; else cout<<"NO\n";
        }
        else
        {
            int pos;
            cin>>pos;
            int new_pos=find_new_pos(pos);
            update(1,1,n,new_pos);
            fw.update(new_pos);
        }
    }
}
