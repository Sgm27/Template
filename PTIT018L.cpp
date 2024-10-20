#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 

int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        int b,n;
        ll ans=0;
        cin>>b>>n;
        while (n)
        {
            ans+=(n%b)*(n%b);
            n/=b;
        } 	
        cout<<ans<<"\n";
    }
}

