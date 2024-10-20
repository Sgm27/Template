#include <bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
ll res;
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
int main()
{
	freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		res=1;
		ll n;
		cin>>n;
		ll i=2;
		while (n!=1)
		{
			ll cnt=0;
			while (n%i==0) 
			{
				n=n/i;
				cnt++;
			}
			if (cnt!=0) res*=((Pow(i,cnt+1)-1)/(i-1));
			i++;
		}
		cout<<res<<endl;
	}
}
