#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
int n,a[300005];
void input()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
}
ll f(int x)
{
    ll sum=0;
    for (int i=1;i<=n;i++) sum+=abs(x-a[i]);
    return sum;
}
void process()
{
    a[n+1]=2e9;
    sort(a+1,a+1+n);
    int l=1,r=n+1;
    while (r-l>4)
    {
        int m1=(l+r)/2;
        int m2=m1+1;
        if (f(a[m1])>f(a[m2])) l=m1;
        else r=m2;
    }
    ll Min=1e18,ans;
    for (int i=l;i<=r;i++)
    {
        ll tmp=f(a[i]);
        if (tmp<Min)
        {
            Min=tmp;
            ans=a[i];
        }
    }
    cout<<ans<<"\n";
    cout<<f(78674316)<<" "<<f(ans);
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
}

