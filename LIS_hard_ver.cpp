#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define INPUT if (fopen("thu.inp","r")) freopen("thu.inp","r",stdin)
#define maxn 30004
int n,a[maxn],b[maxn],ans;
int main()
{
    INPUT;
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    fill(b+1,b+1+n,INT_MAX);
    b[1]=INT_MIN;
    for (int i=1;i<=n;i++)
    {
        int k=lower_bound(b+1,b+1+n,a[i])-b;
        b[k]=a[i];
        ans=max(ans,k-1);
    }
    cout<<ans;
}


