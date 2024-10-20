//https://youtu.be/S5_lmrDgSB0
#include<iostream>
using namespace std;
using ll = long long;
#define maxn 10005
int n,k,T[maxn],f[15][maxn],a[maxn];
const int mod=1e9;
void input()
{
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
}
ll Get(int x)
{
    ll ans=0;
    while (x<=n)
    {
        ans=(ans+T[x])%mod;
        x+=(x&(-x));
    }
    return ans;
}
void Update(int x,ll val)
{
    while (x>0)
    {
        T[x]=(T[x]+val)%mod;
        x-=(x&(-x));
    }
}
void process()
{
    for (int i=1;i<=n;i++) f[1][i]=1;
    for (int p=2;p<=k;p++)
    {
        for (int i=1;i<=n;i++) T[i]=0;
        for (int i=1;i<=n;i++)
        {
            f[p][i]=Get(a[i]+1);
            Update(a[i],f[p-1][i]);
        }
    }
    ll res=0;
    for (int i=1;i<=n;i++) res=(res+f[k][i])%mod;
    cout<<res;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
}

