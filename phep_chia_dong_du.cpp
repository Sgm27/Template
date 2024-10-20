#include <bits/stdc++.h>
using namespace std;
int n,a[105];
int main()
{
//	freopen("thu.inp","r",stdin);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	int tmp=abs(a[2]-a[1]);
	for (int i=3;i<=n;i++) tmp=__gcd(tmp,abs(a[i]-a[i-1]));
	vector<int> res;
	for (int i=2;i<=sqrt(tmp);i++)
		if (tmp%i==0)
		{
			res.push_back(i);
			if (i!=tmp/i) res.push_back(tmp/i);
		}
	res.push_back(tmp);
	sort(res.begin(),res.end());
	for (int x : res) cout<<x<<" ";
}
