#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 41
int n;
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    if (n<=3)
    {
        ll res=1;
        for (int i=1;i<=n;i++) 
        {
            cout<<res<<" ";
            res*=2;
        }
        return 0;
    }
    for (int i=1;i<=n;i++) cout<<n+i<<" ";
}

