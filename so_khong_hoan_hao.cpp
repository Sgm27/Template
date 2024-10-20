#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll a,b,prime[10000001],kq=0;
void input()
{
	cin>>a>>b;
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
void sang()
{
	for (ll i=1;i<=10000000;i++)
	{
		prime[i]=i;
	}
	for (ll i=2;i<=sqrt(10000000);i++)
		if (prime[i])
		{
			for (ll j=i*i;j<=10000000;j+=i)
				if (prime[j]==j) prime[j]=i;
		}
}
ll tong_uoc(ll n)
{
	ll res=1,x=n;
	while (n!=1)
	{
		int cnt=0;
		int tmp=prime[n];
		while (n%tmp==0)
		{
			cnt++;
			n/=tmp;
		}
		res*=((Pow(tmp,cnt+1)-1)/(tmp-1));
	}
	return res-x;
}
ll process(ll n)
{
	return abs(n-tong_uoc(n));
}
int main()
{
	sang();
//	freopen("thu.inp","r",stdin);
	input();
	for (ll i=a;i<=b;i++)
		{
			kq+=process(i);
		}
	cout<<kq;
}
