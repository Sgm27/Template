#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,k,a[100005];
void input()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
}
void process()
{
	sort(a+1,a+n+1);
	int i=1,cnt=0;
	a[n+1]=9999999;
	while (i<=n)
	{
		if ((a[i+1]-a[i])>k) cnt++;
		i++;
	}
	cout<<cnt;
}
int main()
{
	//freopen("thu.inp","r",stdin);
	input();
	process();
}

