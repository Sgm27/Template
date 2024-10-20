#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[4];
void process()
{
	sort(a+1,a+4);
	cout<<a[3]-a[1]<<endl;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	ll tc;
	cin>>tc;
	while (tc--)
	{
		cin>>a[1]>>a[2]>>a[3];
		process();
	}
}
