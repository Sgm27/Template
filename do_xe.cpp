#include <bits/stdc++.h>
using namespace std;
int a,b,c;
map<double,int> mp;
int main()
{
	//freopen("thu.inp","r",stdin);
	cin>>a>>b>>c;
	for (int i=1;i<=3;i++)
	{
		int x,y;
		cin>>x>>y;
		for (int k=x;k<y;k++) mp[k+0.5]++;
	}
	int res=0;
	for (pair<double,int> k : mp)
	{
		if (k.second==1) res+=a;
		if (k.second==2) res+=b*2;
		if (k.second==3) res+=c*3;
	}
	cout<<res;
}
