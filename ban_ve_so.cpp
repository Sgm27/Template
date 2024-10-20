#include <bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("thu.inp","r",stdin);
	int n;
	while (cin>>n)
	{
		if (n==0) return 0;
		set<int> se;
		for (int i=1;i<=6*n;i++) 
		{
			int x; cin>>x;
			se.insert(x);
		}
		if (se.size()==49) cout<<"Yes\n"; else cout<<"No\n";
	}
}
