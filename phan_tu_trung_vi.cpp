#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	freopen("thu.inp","r",stdin);
	ll tc,tt,n,a[10005]; cin>>tc;
	while (tc--)
	{
		ll cnt=0;
		vector<ll> v;
		cin>>tt>>n;
		cout<<tt<<" "<<n/2+1<<endl;
		for (int i=1;i<=n;i++) 
		{
			cin>>a[i];
			v.push_back(a[i]);
			if (i%2)
			{
				cnt++;
				sort(v.begin(),v.end());
				cout<<v[i/2]<<" ";
				if (cnt%10==0) cout<<endl;
			}
		}
		if (cnt%10) cout<<endl;
	}
}
