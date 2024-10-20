#include <bits/stdc++.h>
using namespace std;
int n,a[105],b[105];
bool process()
{
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	for (int i=1;i<=n;i++) 
		if (a[i]>b[i]) return 0;
	return 1;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc; cin>>tc;
	while (tc--)
	{
		cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i];
		for (int i=1;i<=n;i++) cin>>b[i];
		if (process()) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
