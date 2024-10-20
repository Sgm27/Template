#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll res[505];
vector<ll> v;
void init()
{
    queue<ll> Q;
    Q.push(9);
    while (!Q.empty())
    {
        ll x=Q.front();
        Q.pop();
        v.push_back(x);
        if (1ll*x*10<=1e15) Q.push(x*10);
        if (1ll*x*10+9<=1e15) Q.push(x*10+9);
    }
    for (int i=1;i<=500;i++)
        for (ll k : v) 
            if (k%i==0)
            {
                res[i]=k;
                break;
            }
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    init();
    int tc; cin>>tc;
    while (tc--)
    {
        int n;
        cin>>n;
        cout<<res[n]<<endl;
    }
}

