#include <bits/stdc++.h>
using namespace std;
int a[105][105],n;
bool d[105][105];
void process()
{
	set<int> nhom1;
	set<int> nhom2;
	for (int i=1;i<=n;i++)
	{
		bool ok=true;
		for (int x : nhom1) if (!d[i][x]) 
		{
			ok=false;
			break;
		}
		if (ok) 
		{
			nhom1.insert(i);
			continue;
		}
		ok=true;
		for (int x : nhom2) if (!d[i][x]) 
		{
			ok=false;
			break;
		}
		if (ok)
		{
			nhom2.insert(i);
			continue;
		}
		if (!ok) 
		{
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
}
int main()
{
	//freopen("thu.inp","r",stdin);
	while (cin>>n)
	{
		memset(d,true,sizeof(d));
		if (n==0) return 0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
			{
				int x; cin>>x;
				if (x==1) 
				{
					d[i][j]=false;
					d[j][i]=false;
				}
			}
		process();
	}
}
