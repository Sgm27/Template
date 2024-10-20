#include <bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("thu.inp","r",stdin);
	set<int> se;
	int n;
	while (cin>>n) se.insert(n%42);
	cout<<se.size();
}
