#include <bits/stdc++.h>
using namespace std;
int n,a[100005];
void process()
{
	map<int,int> mp;
	cin>>n;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
		mp[a[i]]++;
	}
	for (int i=1;i<=n;i++)
		if (mp[a[i]]>1) 
		{
			cout<<a[i]<<endl;
			return;
		}
	cout<<"NO\n";
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--) process();
}
