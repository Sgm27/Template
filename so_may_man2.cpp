#include <bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		int n; cin>>n;
		map<int,int> mp;
		int Max=INT_MIN;
		for (int i=1;i<=n;i++) 
		{
			int x; cin>>x;
			mp[x]++;
			Max=max(Max,mp[x]);
		}
		for (pair<int,int> k : mp)
			if (k.second==Max) 
			{
				cout<<k.first<<endl;
				break;
			}
	}
}
