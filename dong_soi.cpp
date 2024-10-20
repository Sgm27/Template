#include  <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,a[100005];
void input()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
}
void process()
{
    ll res=0;
    priority_queue<ll , vector<ll> , greater<ll>> q;
    for (int i=1;i<=n;i++) q.push(a[i]);
    while (q.size()>1)
    {
        ll x=q.top();
        q.pop();
        ll y=q.top();
        q.pop();
        q.push(x+y);
        res+=x+y;
        
    }
    cout<<res;
}
int main()
{
    freopen("thu.inp","r",stdin);
    freopen("thu.out","w",stdout);
    input();
    process();
}
