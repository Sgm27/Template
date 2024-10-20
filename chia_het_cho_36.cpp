#include <bits/stdc++.h>
using namespace std;
bool bigmod(string s)
{
	int res=0;
	for (char k : s)
	{
		res=(res*10+(k-'0'))%36;
	}
	return res==0;
}
int main()
{
	//freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		string tmp;
		cin>>tmp;
		if (bigmod(tmp)) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
