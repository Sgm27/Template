#include <bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
ll a[35],tu,mau;
void init()
{
	a[1]=1;
	for (int i=2;i<=30;i++)
	{
		tu=mau=1;
		for (int k=2;k<=i;k++) 
		{
			tu*=(i+k);
			mau*=k;
			ll tmp=__gcd(tu,mau);
			if (tmp!=1) 
			{
				tu/=tmp;
				mau/=tmp;
			}
		}
		a[i]=tu/mau;
	}
}
int main()
{
	init();
	freopen("thu.inp","r",stdin);
	freopen("thu.out","w",stdout);
	while (1)
	{
		int n;
		cin>>n;
		if (n==0) return 0;
		cout<<a[n]<<endl;
	}
}
