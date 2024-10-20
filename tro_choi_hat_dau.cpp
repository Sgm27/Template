#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[100005];
void input()
{
	cin>>n;
	for (int i=0;i<=n;i++) cin>>a[i];
}
void process()
{
	ll res=0;
	int i=n;
	while (i>0)
	{
		a[i]+=res;
		if (a[i]%i!=0) 
		{
			cout<<"No";
			return;
		}
		else res+=(ll)(a[i]/i);
		i--;
	}
	cout<<"Yes";
}
int main()
{
//	freopen("thu.inp","r",stdin);
	input();
	process();
}
