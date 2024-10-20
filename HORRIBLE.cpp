#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
#define maxn 100005
int n,q,bit1[maxn],bit2[maxn];
void up_point(int fw[],int x,int val)
{
    for (;x<=n;x+=x&-x) fw[x]+=val;
}
void up_range(int l,int r,int val)
{
    up_point(bit1,l,(n-l+1)*val);
    up_point(bit1,r+1,-(n-r)*val);
    up_point(bit2,l,val);
    up_point(bit2,r+1,-val);
}
int getSum(int fw[],int x)
{
    int ans=0;
    for(;x>0;x-=x&-x) ans+=fw[x];
    return ans;
}
int prefixSum(int x)
{
    return getSum(bit1,x)-getSum(bit2,x)*(n-x);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n>>q;
        FOR(i,1,n) bit1[i]=bit2[i]=0;
        while (q--)
        {
            int type,u,v,val;
            cin>>type>>u>>v;
            if (type==0)
            {
                cin>>val;
                up_range(u,v,val);
            }
            else 
                cout<<prefixSum(v)-prefixSum(u-1)<<"\n";
        } 	
    }
}
