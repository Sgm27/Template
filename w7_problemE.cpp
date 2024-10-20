#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 1000006
ll n,a[maxn];
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    while (1)
    {
        ll x; cin>>x;
        if (x==-1) return 0;
        if (binary_search(a+1,a+1+n,x)) cout<<"1\n";
        else cout<<"0\n";
    }
}

