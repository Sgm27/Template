#include <bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("thu.inp","r",stdin);
	int n,k;
	cin>>n>>k;
	int a[n+5];
	for (int i=0;i<=n;i++) cin>>a[i];
	sort(a,a+n);
	cout<<a[k];
}
