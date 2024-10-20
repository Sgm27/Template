#include <bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("thu.inp","r",stdin);
	int n,a[30];
	while (cin>>n)
	{
		if (n==0) return 0;
		for (int i=1;i<=n;i++) cin>>a[i];
		int dem=1;
		for (int i=1;i<=n;i++)
		{
			int cs=i;
			while (dem<=a[i])
			{
				cout<<cs<<" ";
				dem++;
			}
		}
		cout<<endl;
	}
}
