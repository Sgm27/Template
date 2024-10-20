#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
void input()
{
	cin>>n;
}
ll tongcs(ll k)
{
	ll sum=0;
	if (k<=9) return k;
	while (k)
	{
		sum+=k%10;
		k/=10;
	}
	return sum;
}
void process()
{
	if (n<=3) 
	{
		cout<<"NO";
		return;
	}
	ll m=n;
	ll i=2,sum=0;
	while (n!=1)
	{
		while (n%i==0) 
		{
			sum+=tongcs(i);
			n/=i;
		}
		i++;
	}
	if (sum==tongcs(m)) cout<<"YES";
	else cout<<"NO";
}
int main()
{
//	freopen("thu.inp","r",stdin);
	input();
	process();
}
