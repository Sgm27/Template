#include <bits/stdc++.h>
using namespace std;
bool check(string a,string b)
{
	for (int i=1;i<a.length();i++)
	{
		if (abs((int)(a[i])-(int)(a[i-1]))!=abs((int)(b[i])-(int)(b[i-1]))) return false;
	}
	return true;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc; cin>>tc;
	while (tc--)
	{
		string s;
		cin>>s;
		string tmp=s;
		reverse(tmp.begin(),tmp.end());
		if (check(tmp,s)) cout<<"YES\n"; else cout<<"NO\n";
	}
}
