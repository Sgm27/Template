#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[105],csmin,csmax,Max=INT_MIN,Min=INT_MAX;
int main()
{
	//freopen("thu.inp","r",stdin);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		if (a[i]>Max) 
		{
			Max=a[i];
			csmax=i;
		}
		if (a[i]<=Min) 
		{
			Min=a[i];
			csmin=i;
		}
	}
	if (csmax>csmin) cout<<(csmax-1)+(n-csmin-1);
	else cout<<(csmax-1)+(n-csmin);
}
