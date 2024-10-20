#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 1005
ll a[maxn],n;
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    ll tmp=sqrt(n*(n+1)/2)+1;
    for (int i=1;i<n;i++) a[i]=i;
    a[n]=tmp*tmp-(n*(n-1))/2;
    for (int i=1;i<=n;i++) cout<<a[i]<<" ";
}

