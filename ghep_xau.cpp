#include <bits/stdc++.h>
using namespace std;
string a[15];
bool cmp(string a,string b)
{
	return a+b<b+a;
}
int main()
{
	//freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		int n; cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n,cmp);
		for (int i=1;i<=n;i++) cout<<a[i]; cout<<endl;
	}
}
