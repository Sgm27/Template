#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int prime[1000005];
void sang()
{
	for (int i=0;i<=1000000;i++) prime[i]=1;
	prime[0]=0; prime[1]=0;
	for (int i=2;i<=sqrt(1000000);i++)
		if (prime[i])
		for (int j=i*i;j<=1000000;j+=i) prime[j]=0;
}
int main()
{
	//freopen("thu.inp","r",stdin);
	sang();
	ll n;
	cin>>n;
	for (int i=2;i<=1000000;i++)
	{
		if (i>n) break;
		if (prime[i] && n%i==0 && n%(i*i*i)==0) 
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
}

