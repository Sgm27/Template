#include <bits/stdc++.h>
using namespace std;
string a[25],res[25];
int n,k;
bool d[25];
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc; cin>>tc;
	while (tc--)
	{
		cin>>n>>k;
		for (int i=1;i<=n;i++) res[i]="#";
		for (int i=1;i<=n;i++) d[i]=true;
		for (int i=1;i<=n;i++) cin>>a[i];
		while (k--)
		{
			int x,y;
			cin>>x>>y;
			res[y]=a[x];
			d[x]=false;
		}
		vector<string> v;
		v.push_back("#");
		for (int i=1;i<=n;i++) 
			if (d[i]) v.push_back(a[i]);
		int i=1,j=1;
		while (i<=n)
		{
			if (res[i]=="#") cout<<v[j++]<<" ";
			else cout<<res[i]<<" ";
			i++;
		}
		cout<<endl;
	}
}

