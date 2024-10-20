#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
int a[maxn],n,b[maxn],c[maxn];
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int Max=0,cnt_zero=0;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i], Max=max(Max,a[i]);
    for (int i=1;i<=n;i++)
    {
        int x; cin>>x;
        c[i]=a[i]; b[i]=x;
        a[i]-=x;
        if (a[i]<0) return cout<<"-1", 0;
        if (!a[i]) cnt_zero++;  
    }
    int ans=0;
    for (int i=1;i<=n;i++)
        ans=__gcd(ans,a[i]);
    if (cnt_zero==n) return cout<<Max+1, 0;
    if (cnt_zero) return cout<<"-1", 0;
    bool flag=true;
    for (int i=1;i<=n;i++)
        if (c[i]%ans!=b[i]) 
        {
            flag=false;
            break;
        }
    if (flag) cout<<ans; else cout<<"-1";
}

