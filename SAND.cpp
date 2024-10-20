#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define pii pair<int,int>
using ll = long long;
#define maxn 

int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll a,s;
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>a>>s;
        bool flag=false;
        if (2*a<=s)
        {
            ll tmp=s-2*a;
            if ((tmp&a)==0) flag=true;
        }	
        if (flag) cout<<"Yes\n"; else cout<<"No\n";
    }
}
