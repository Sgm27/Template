#include <bits/stdc++.h>
using namespace std;
void process(string s)
{
	if (s.length()==1) 
	{
		cout<<s<<endl;
		return;
	}
	while (s.length()>1)
	{
		int res=0;
		for (char x:s) res+=(x-'0');
		s=to_string(res);
	}
	cout<<s<<endl;
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
		process(s);
	}
}
