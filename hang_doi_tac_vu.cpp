#include <bits/stdc++.h>
using namespace std;
int a[55];
int main()
{
	freopen("thu.inp","r",stdin);
	int tc; cin>>tc;
	while (tc--)
	{
		int n,s;
		bool check=false;
		cin>>n>>s;
		for (int i=1;i<=n;i++) cin>>a[i];
		int sum=0;
		for (int i=1;i<=n;i++)
		{
			sum+=a[i];
			if (sum>s) 
			{
				cout<<i-1<<endl;
				check=true;
				break;
			}
		}
		if (!check) cout<<n<<endl;
	}
}
