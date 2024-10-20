#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 1000005
ll n,a[maxn];
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (n==1) return cout<<a[1], 0;

    ll Min=a[1];
    ll Max=a[1];
    for (int i=2;i<=n;i++)
    {
        // cout<<Min<<" "<<Max;
        Min=min(Min,a[i]);
        Max=max(Max,a[i]);
        Min=min({Min,Min-Max/2,Max+Min/2});
        Max=max({Max,Min-Max/2,Max+Min/2});
        cout<<(Min+Max)/2<<" ";
    }
}

