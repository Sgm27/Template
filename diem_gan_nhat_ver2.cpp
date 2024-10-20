#include<iostream>
#include<algorithm>
#define maxn 300005
using namespace std;
using ll = long long;
ll n,getL[maxn],getR[maxn];
struct mang{
    ll gt,cs;
};
mang a[maxn];
void input()
{
    cin>>n;
    for (int i=1;i<=n;i++) 
    {
        cin>>a[i].gt;
        a[i].cs=i;
    }
}
bool cmp(mang a,mang b)
{
    if (a.gt!=b.gt) return a.gt<b.gt;
    return a.cs<b.cs;
}
void buildL()
{
    getL[0]=0;
    for (int i=1;i<=n;i++)
        getL[i]=getL[i-1]+(a[i].gt-a[i-1].gt)*(i-1);
}
void buildR()
{
    int cs=0;
    getR[n+1]=0;
    for (int i=n;i>=1;i--)
        getR[i]=getR[i+1]+(a[i+1].gt-a[i].gt)*cs++;
}
void process()
{
    sort(a+1,a+1+n,cmp);
    buildL();
    buildR();
    ll Min=1e18,ans,cs;
    for (int i=1;i<=n;i++) 
        if (getL[i]+getR[i]<Min)
        {
            Min=getL[i]+getR[i];
            cs=i;
            ans=a[i].gt;
        }
    cout<<ans;
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
}

