#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
int n,a[200005],max_mod=0;
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n,greater<int>());
    for (int i=1;i<=n-1;i++)
    {
        if (max_mod>a[i]) 
        {
            cout<<max_mod;
            return 0;
        }
        for (int j=i+1;j<=n;j++) 
        {
            if (max_mod>a[j]) break;
            max_mod=max(max_mod,a[i]%a[j]);
        }
    }
    cout<<max_mod;
}

