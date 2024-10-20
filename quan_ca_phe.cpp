#include <bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> mp;
int main()
{
//	freopen("thu.inp","r",stdin);
	int n;
	cin>>n;
	while (n--)
	{
		int h,m;
		cin>>h>>m;
		mp[{h,m}]++;
	}
	int Max=-1;
	for (auto it : mp) Max=max(Max,it.second);
	cout<<Max;
}
