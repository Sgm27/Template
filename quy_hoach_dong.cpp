#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld=long double;
#define maxn 1005
const ld eps=1e-9;
int n,s,remain;
struct mang{
    int x,y,k;
    ld r;
};
mang a[maxn];
void input()
{
    cin>>n>>s;
    remain=1e6-s;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y>>a[i].k;
        a[i].r=(ld)((ld)sqrt(1.0*a[i].x*a[i].x+1.0*a[i].y*a[i].y));
    }
}
int f(ld x)
{
    int sum=0;
    for (int i=1;i<=n;i++) 
        if (x+eps>a[i].r) sum+=a[i].k;
    return sum;
}
void process()
{
    int s=0;
    for (int i=1;i<=n;i++) s+=a[i].k;
    if (s<remain) 
    {
        cout<<"-1";
        return;
    }
    ld l=0,r=1e18;
    while (r-l>eps)
    {
        ld mid=(l+r)/2.0;
        if (f(mid)>=remain) r=mid;
        else l=mid;
    }
    cout<<fixed<<setprecision(7)<<l;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
}

