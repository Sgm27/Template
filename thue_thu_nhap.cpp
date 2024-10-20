#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void process(ll s)
{
	if (s<1000000) 
	{
		cout<<s<<endl;
		return;	
	}	
	if (s>=1000000 && s<5000000) 
	{
		cout<<s/10*9<<endl;
		return;
	}
	if (s>=5000000)
	{
		cout<<s/5*4<<endl;
		return;
	}
}
int main()
{
	//freopen("thu.inp","r",stdin);
	ll n;
	while (cin>>n)
	{
		if (n==0) return 0;
		process(n);
	}
}
