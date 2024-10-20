#include <bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc; cin>>tc;
	while (tc--)
	{
		int n,Max=INT_MIN,Min=INT_MAX;
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			int x; cin>>x;
			Min=min(Min,x);
			Max=max(Max,x);
		}
		cout<<(Max-Min)*2<<endl;
	}
}
