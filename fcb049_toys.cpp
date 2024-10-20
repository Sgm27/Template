#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 

int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    if (k>=n*2) cout<<0;
    else
    {
        if (k<=n) return cout<<(k-1)/2, 0;
        ll tmp=k-n;
        cout<<(n-tmp+1)/2;
    }
}

