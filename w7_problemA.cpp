#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 
const ll MOD=1e9+7;
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        ll a,b;
        cin>>a>>b;
        cout<<((a%MOD)*(b%MOD))%MOD<<"\n";
    }
}

