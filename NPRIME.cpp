#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 
const int N=1e7;
vector<ll> nt;
int prime[N+5];
ll n;
bool cp(ll x)
{
    ll tmp=sqrt(x);
    return tmp*tmp==x;
}
void sang()
{
    for (int i=1;i<=N;i++) prime[i]=1;
    prime[0]=prime[1]=0;
    for (int i=2;i<=sqrt(N);i++)
        if (prime[i])
            for (int j=i*i;j<=N;j+=i) prime[j]=0;
    for (ll i=1;i<=N;i++)
        if (prime[i]) nt.push_back(i);
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    // sang();
    // 1333313 10007
    // cout<<1ll*1333313*1333313*10007;
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n;   
        for (ll x=2;x<=1e7;x++)
            if (n%(x*x)==0) 
            {
                cout<<x<<" "<<n/(x*x)<<"\n";
                break;
            }
            else 
            if (n%x==0 && cp(n/x))
            {
                cout<<sqrt(n/x)<<" "<<x<<"\n";
                break;
            }
    }
}
