#include <bits/stdc++.h>
using namespace std;
bool process(string s)
{
	if (s.length()<2) return false;
	if (s[s.length()-2]=='8' && s[s.length()-1]=='6') return true;
	return false;
}
int main()
{
	freopen("thu.inp","r",stdin);
	int tc; cin>>tc;
	while (tc--)
	{
		string s;
		cin>>s;
		cout<<process(s)<<endl;
	}
}
