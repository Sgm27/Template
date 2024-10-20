#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 2005
struct mang{
    int f,s,id,Min,Max;
};
int n;
mang a[maxn];
bool cmp1(mang a,mang b)
{
    if (a.f!=b.f) return a.f<b.f;
    return a.s<b.s;
}
bool cmp2(mang a,mang b)
{
    if (a.s!=b.s) return a.s<b.s;
    return a.f<b.f;
}
bool cmp3(mang a,mang b)
{
    return a.id<b.id;
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++) 
    {
        cin>>a[i].f>>a[i].s;
        a[i].id=i;
    }
    sort(a+1,a+1+n,cmp1);
    // for (int i=1;i<=n;i++) cout<<a[i].f<<" "<<a[i].s<<"\n";
    for (int i=1;i<=n;i++)
    {
        int idx=upper_bound(a+1,a+1+n,a[i],cmp1)-a-1;
        a[i].Min=n-idx+1;
        a[i].Max=n-idx+1;
    }
    sort(a+1,a+1+n,cmp2);
    for (int i=1;i<=n;i++)
    {
        int idx=upper_bound(a+1,a+1+n,a[i],cmp2)-a-1;
        a[i].Min=max(a[i].Min,n-idx+1);
        a[i].Max=min(a[i].Max,n-idx+1);
    }
    sort(a+1,a+1+n,cmp3);
    // for (int i=1;i<=n;i++) cout<<a[i].f<<" "<<a[i].s<<'\n';
    for (int i=1;i<=n;i++) cout<<a[i].Max<<" "<<a[i].Min<<"\n";
}

