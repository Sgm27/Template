#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD=1e9+7;
ll gt[1000006],n,a,b;
set<ll> se;
vector<ll> v;
void input()
{
    cin>>a>>b>>n;
}
void init()
{
    gt[0]=1;
    for (int i=1;i<=1000000;i++) gt[i]=(gt[i-1]*i)%MOD;
}
void sinh(ll a,ll b)
{
    ll maxn=1e7;
    queue<ll> Q;
    Q.push(a);
    Q.push(b);
    se.insert(a);
    se.insert(b);
    if (a>b) swap(a,b);
    while (!Q.empty())
    {
        ll x=Q.front();
        Q.pop();
        if (x*10+a<=maxn) 
        {
            se.insert(x*10+a);
            Q.push(x*10+a);
        }
        if (x*10+b<=maxn) 
        {
            se.insert(x*10+b);
            Q.push(x*10+b);
        }
    }
    for (ll k : se) v.push_back(k);
}
ll calc(ll k)
{
    ll i=1,tmp1,tmp2;
    for (int i=k;i<=)
}
void process()
{
    swap(a,b);
    ll res=0;
    for (ll sd : v)
    {
        if (sd>=10*b)
        {
            ll i=(sd-10*b)/(a-b);
            res+=calc(i);
        }
    }
    cout<<res;
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    init();
    input();
    sinh(a,b);
    process();
}

