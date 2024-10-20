#include <bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("thu.inp","r",stdin);
	string s;
	while (cin>>s)
	{
		if (s=="#") return 0;
		map<char,int> mp;
		int cmp=s.length()/2+s.length()%2;
		for (char x : s) mp[x]++;
		if (mp['A']>=cmp) cout<<"need quorum\n";
		else 
		if (mp['Y']>mp['N']) cout<<"yes\n";
		else 
		if (mp['N']>mp['Y']) cout<<"no\n";
		else cout<<"tie\n";
	}
}
