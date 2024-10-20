#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,s,a[100005],sum[100005];
void process()
{
	sum[0]=0;
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	if (sum[n]<s) 
	{
		cout<<0<<endl;
		return;
	}
	ll res=INT_MAX;
	for (int i=0;i<=n;i++)
	{
		auto it=upper_bound(sum,sum+n+1,sum[i]+s);
		if (it!=sum+n+1)
		{
			ll cs=it-sum;
			res=min(res,cs-i);
		}
	}
	cout<<res<<endl;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		cin>>n>>s;
		for (int i=1;i<=n;i++) cin>>a[i];
		process();
	}
}
