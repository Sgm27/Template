#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define pii pair<int,int>
using ll = long long;
#define maxn 
bool nt(ll a)
{
    if (a==3 || a==2) return true;
    if (a%2==0 || a%3==0 || a<2) return false;
    int i=5;
    while (i<=sqrt(a))
    {
        if (a%i==0 || (a%(i+2))==0) return false;
        i+=6;
    }
    return true;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll i=2,ans=n;
    if (nt(n)) return cout<<n*n, 0; 
    while (n!=1)
    {
        int cnt=0;
        while (n%i==0) n/=i, cnt++;
        if (cnt%2) ans*=i;
        i++;
    }
    cout<<ans;
}
