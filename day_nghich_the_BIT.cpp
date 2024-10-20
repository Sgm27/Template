#include<iostream>
using namespace std;
using ll = long long;
#define maxn 60005
int T[maxn];
int n,a[maxn];
void Update(int x,int val)
{
    while (x<=maxn)
    {
        T[x]+=val;
        x+=(x&(-x));
    }
}
int Get(int x)
{
    int ans=0;
    while (x>0)
    {
        ans+=T[x];
        x-=(x&(-x));
    }
    return ans;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int res=0;
    for (int i=n;i>=1;i--)
    {
        Update(a[i],1);
        res+=Get(a[i]-1);
    }
    cout<<res;
}

