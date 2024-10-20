#include <bits/stdc++.h>
using namespace std;
void process(string s)
{
	s+="#";
	int dem=1;
	for (int i=0;i<s.length()-1;i++)
	{
		if (s[i]!=s[i+1])
		{
			cout<<dem<<s[i];
			dem=1;
		}
		else dem++;
	}
	cout<<endl;
}
int main()
{
	//freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		string s;
		cin>>s;
		process(s);
	}
}
