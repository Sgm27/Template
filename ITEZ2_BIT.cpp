// Fenwick tree
#include<iostream>
using namespace std;
using ll = long long;
#define maxn 100005
ll t[maxn],n,q,a[maxn];
void update(int x,int val)
{
    while (x<=n)
    {
        t[x]+=val;
        x+=(x&(-x));
    }
}
ll get(int x)
{
    ll ans=0;
    while (x>0)
    {
        ans+=t[x];
        x-=(x&(-x));
    }
    return ans;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    while (q--)
    {
        int type; cin>>type;
        if (type==1)
        {
            int x,y;
            cin>>x>>y;
            update(x,y-a[x]);
            a[x]=y;
        }
        else
        {
            int l,r;
            cin>>l>>r;
            cout<<get(r)-get(l-1)<<"\n";
        }
    }
}

