#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 10004
int n,m,a[maxn],b[55];
bool f(int x)
{
    int l1=1,l2=1;
    while (l1<=n && l2<=m)
    {
        if (a[l1]>=b[l2]-x && a[l1]<=b[l2]+x) l1++;
        else l2++;
        if (l1>n) return true;
    }
    return false;
}
void process()
{
    if (f(0))
    {
        cout<<"0\n";
        return;
    }
    int l=0,r=1e9+5;
    while (r-l>1)
    {
        int m=(l+r)/2;
        if (f(m)) r=m;
        else l=m;
    }
    cout<<r<<"\n";
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n>>m;
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int j=1;j<=m;j++) cin>>b[j];
        sort(a+1,a+1+n);
        sort(b+1,b+1+m);
        process();
    }
}

