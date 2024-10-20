#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 100005
int n,a[maxn],q;
struct node{
    int m1,m2;
} t[maxn*4];
node operator+(node l,node r)
{
    node answer;
    if (l.m1 > r.m1) 
    {
        answer.m1=l.m1;
        answer.m2=max(l.m2,r.m1);
    }
    else
    {
        answer.m1=r.m1;
        answer.m2=max(r.m2,l.m1);
    }
    return answer;
}
void update(int id,int l,int r,int p,int val)
{
    if (r<p || l>p) return;
    if (l==r) 
        return t[id]={val,0}, void();
    int m=l+r >> 1;
    update(id << 1,l,m,p,val);
    update(id << 1 | 1,m+1,r,p,val);
    t[id] = t[id << 1] + t[id << 1 | 1];
}
node get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return {0,0};
    if (l>=u && r<=v) return t[id];
    int m = l+r >> 1;
    return get(id << 1,l,m,u,v) + get(id << 1 | 1,m+1,r,u,v);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n) 
    {
        cin>>a[i];
        update(1,1,n,i,a[i]);
    }
    cin >> q;
    while (q--)
    {
        char type;
        int u,v;
        cin>>type>>u>>v;
        if (type=='Q') 
        {
            node ans=get(1,1,n,u,v);
            cout<<ans.m1+ans.m2<<"\n";
        }
        else
            update(1,1,n,u,v);
    }
}   
