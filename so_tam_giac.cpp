#include<iostream>
#include<set>
#include<math.h>
using namespace std;
using ll = long long;
set<ll> se;
ll n;
void input()
{
    cin>>n;
}
void process()
{
    for (ll i=1;sqrt(2*n)+1;i++) 
    {
        se.insert(i*(i+1)/2);
        if (se.count(n-i*(i+1)/2)) 
        {
            cout<<"YES";
            return;
        }
    }
    cout<<"NO";
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
}

