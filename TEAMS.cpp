#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 

int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll a,b,n;
    cin>>a>>b>>n;
    ll teams=min(a/2,b);
    n-=(a+b-teams*3);
    while (n>0) n-=3, teams--;
    cout<<teams;
}

