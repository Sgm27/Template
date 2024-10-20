#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 105
int a[maxn],b[maxn],n,m;
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    cin>>m;
    for (int i=1;i<=m;i++) cin>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    int l1=1,l2=1,res=0;
    while (l1<=n && l2<=m)
    {
        if (abs(a[l1]-b[l2])<=1)
        {
            res++;
            l1++;
            l2++;
        }
        else
        if (a[l1]>b[l2]) l2++;
        else
        if (a[l1]<b[l2]) l1++;
    }
    cout<<res;
}

