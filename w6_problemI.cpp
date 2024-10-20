#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
#define maxn 
vector<ll> v;
ll N=1e10;
ll n;
bool check(ll x)
{
    int d4,d7;
    d4=d7=0;
    while (x)
    {
        if (x%10==4) d4++;
        else d7++;
        x/=10;
    }
    return d4==d7;
}
void process()
{
    queue<ll> Q;
    Q.push(1ll*4);
    Q.push(1ll*7);
    while (!Q.empty())
    {
        ll x=Q.front();
        Q.pop();
        if (x*10+4<=N) 
        {
            Q.push(x*10+4);
            if (check(x*10+4)) v.push_back(x*10+4);
        }
        if (x*10+7<=N) 
        {
            Q.push(x*10+7);
            if (check(x*10+7)) v.push_back(x*10+7);
        }
    }
    cout<<*lower_bound(v.begin(),v.end(),n);
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    process();
}

