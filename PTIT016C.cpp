#include <bits/stdc++.h>
using namespace std;
bool check(string s)
{
	int n=s.length();
	s="#"+s;
	for (int i=1;i<=n;i++)
	{
		if ((s[i]-'0')%2-i%2!=0) return false;
	}
	return true;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		string s;
		cin>>s;
		if (check(s)) cout<<"YES\n"; else cout<<"NO\n";
	}
}
