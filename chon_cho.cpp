#include <bits/stdc++.h>
using namespace std;
int n,Max,d[3005];
void input()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int x; cin>>x;
		d[x]=1;
	}
	bool ok=false;
	for (int i=1;i<=n;i++) 
		if (d[i]==0) 
		{
			cout<<i;
			return;
		}
	cout<<n+1;
}
int main()
{
	memset(d,0,sizeof(d));
//	freopen("thu.inp","r",stdin);
	input();
}
