#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll l,r,x,res;
void input()
{
	cin>>l>>r>>x;
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
	bool ok=false;
	ll st=log(l)/log(x);
	ll ed=log(r)/log(x);
	//cout<<st<<" "<<ed;
	if (st==0) res=1; else res=Pow(x,st);
	for (ll i=st;i<=ed;i++)
		{
			if (l<=res && res<=r) 
			{
				cout<<res<<" ";
				ok=true;
			}
			res*=x;
		}
	if (!ok) cout<<"-1";
}
int main()
{
//	freopen("thu.inp","r",stdin);
	input();
	process();
}
