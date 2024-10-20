#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 200005
int n,t[maxn*4],lz[maxn*4],a[maxn];
void build(int id,int l,int r)
{
    if (l==r) return t[id]=a[l], void();
    int m=(l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id]=min(t[id*2],t[id*2+1]); 
}
void Push(int id)
{
    t[id*2]+=lz[id];
    t[id*2+1]+=lz[id];
    lz[id*2]+=lz[id];
    lz[id*2+1]+=lz[id];
    lz[id]=0;
}

void update(int id,int l,int r,int u,int v,int val)
{
    if (r<u || l>v) return;
    if (l>=u && r<=v) 
    {
        t[id]+=val;
        lz[id]+=val;
        return;
    }
    if (lz[id]) Push(id);
    int m=(l+r)/2;
    update(id*2,l,m,u,v,val);
    update(id*2+1,m+1,r,u,v,val);
    t[id]=min(t[id*2],t[id*2+1]);
}
int get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return INF;
    if (l>=u && r<=v) return t[id];
    if (lz[id]) Push(id);
    int m=(l+r)/2;
    return min(get(id*2,l,m,u,v),get(id*2+1,m+1,r,u,v));
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    build(1,1,n);
    int q; cin>>q;
    cin.ignore();
    while (q--)
    {
        string s,t,token[4]; getline(cin,s);
        int idx=0,u,v,val;
        stringstream ss(s);
        while (ss >> t) token[++idx]=t;
        u=stoll(token[1]);
        v=stoll(token[2]);
        if (idx==3)
        {
            val=stoll(token[3]);
            u++, v++;
            if (u<=v)
                update(1,1,n,u,v,val);
            else
            {
                update(1,1,n,u,n,val);
                update(1,1,n,1,v,val);
            }
        }
        else
        {
            u++, v++;
            if (u<=v)
                cout<<get(1,1,n,u,v)<<"\n";
            else
            {
                int t1=get(1,1,n,u,n);
                int t2=get(1,1,n,1,v);
                cout<<min(t1,t2)<<"\n";
            }
        }
    }
}
