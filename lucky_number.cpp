#include <bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
ll res=0;
ll n;
void input()
{
	cin>>n;
}
ll Pow(ll a, ll n)
{
    if(n == 1) {
        return a;
    } else {
        ll temp = Pow(a, n/2);
        if(n % 2 == 0)
            return temp * temp;
        else
            return temp * temp * a;
    }
}
void process()
{
	for (ll i=1;i<=n;i++)
		res+=Pow(2,i);
	cout<<res;
}
int main()
{
	//freopen("thu.inp","r",stdin);
	input();
	process();
}
