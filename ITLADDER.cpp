#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
#define maxn 100005
const int MOD=1e9+7;
int n,q,a[maxn],t[maxn*4];
struct lazy{
    int A,B;
} lz[maxn*4];
void Push(int id,int l,int r,int m)
{
    (t[id*2]+=(m-l+1)*(m+l)*lz[id].A/2+(m-l+1)*lz[id].B)%=MOD;
    (t[id*2+1]+=(r-m)*(r+m+1)*lz[id].A/2+(r-m)*lz[id].B)%=MOD;
    (lz[id*2].A+=lz[id].A)%=MOD;
    (lz[id*2+1].A+=lz[id].A)%=MOD;
    (lz[id*2].B+=lz[id].B)%=MOD;
    (lz[id*2+1].B+=lz[id].B)%=MOD;
    lz[id]={0,0};
}
void update(int id,int l,int r,int u,int v,int a,int b)
{
    if (r<u || l>v) return;
    if (l>=u && r<=v) 
    {
        (t[id]+=a*(r+l)*(r-l+1)/2+(b-u*a)*(r-l+1))%=MOD;
        (lz[id].A+=a)%=MOD;
        (lz[id].B+=b-u*a+MOD*MOD)%=MOD;
        return;
    }
    int m=(l+r)/2;
    if (lz[id].A || lz[id].B) Push(id,l,r,m);
    update(id*2,l,m,u,v,a,b);
    update(id*2+1,m+1,r,u,v,a,b);
    t[id]=(t[id*2]+t[id*2+1])%MOD;
}
int get(int id,int l,int r,int u,int v)
{
    if (r<u || l>v) return 0;
    if (l>=u && r<=v) return t[id];
    int m=(l+r)/2;
    if (lz[id].A || lz[id].B) Push(id,l,r,m);
    int t1=get(id*2,l,m,u,v);
    int t2=get(id*2+1,m+1,r,u,v);
    return (t1+t2)%MOD;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    while (q--)
    {
        int type,u,v,a,b;
        cin>>type>>u>>v;
        if (type==1)
        {
            cin>>a>>b;
            update(1,1,n,u,v,a,b);
        }
        else
            cout<<get(1,1,n,u,v)<<"\n";
    }
}
