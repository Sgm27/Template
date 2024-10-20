//fenwich_tree
#include<iostream>
#include<cstring>
using namespace std;
using ll = long long;
#define maxn 100005
ll T[maxn];
int n,q;
void Update(int x,int val)
{
    while (x<=n)
    {
        T[x]+=val;
        x+=(x&(-x));
    }
}
ll get_sum(int x)
{
    ll sum=0;
    while (x>0)
    {
        sum+=T[x];
        x-=(x&(-x));
    }
    return sum;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>q;
    for (int i=1;i<=n;i++) 
    {
        int x; cin>>x;
        Update(i,x);
    }
    while (q--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if (x==1) Update(y,z);
        else cout<<get_sum(z)-get_sum(y-1)<<"\n";
    }
}

