#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 
vector<ll> v;
ll n;
int cnt;
void process()
{
    queue<ll> Q;
    Q.push(1ll*4);
    Q.push(1ll*7);
    cnt=2;
    while (!Q.empty())
    {
        ll x=Q.front();
        Q.pop();
        if (x*10+4<=n) 
        {
            Q.push(x*10+4);
            v.push_back(x*10+4);
        }
        if (x*10+7<=n) 
        {
            Q.push(x*10+7);
            v.push_back(x*10+7);
        }
    }
    cout<<v.size()+2;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    if (n==4) cout<<"1";
    else if (n==7) cout<<"2";
    else process();
}

