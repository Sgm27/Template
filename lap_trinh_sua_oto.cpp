#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 10005
struct mang{
    ll tp,sn,cs;
    double ts;
};
mang a[maxn];
int n;
bool cmp(mang a,mang b)
{
    return a.ts>b.ts;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++) 
    {
        cin>>a[i].tp;
        a[i].cs=i;
    }
    for (int i=1;i<=n;i++) 
    {
        cin>>a[i].sn;
        a[i].ts=1.0*a[i].tp/a[i].sn;
    }
    sort(a+1,a+1+n,cmp);
    ll res=0,cnt=0;
    for (int i=1;i<=n;i++)
    {
        cnt+=a[i].sn;
        res+=cnt*a[i].tp;
    }
    cout<<res<<"\n";
    for (int i=1;i<=n;i++) cout<<a[i].cs<<" ";
}

