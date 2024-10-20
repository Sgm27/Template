#include <bits/stdc++.h>
using namespace std;
int n,a[105];
int main()
{
//	freopen("thu.inp","r",stdin);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (a[1]%2==1 && a[n]%2==1 && n%2==1) 
		{
			cout<<"yes";
			return 0;
		}
	cout<<"no";
}
