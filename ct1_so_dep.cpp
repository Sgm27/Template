#include <bits/stdc++.h>
using namespace std;
string s;
void process()
{
	if (s[0]=='-') s.erase(s.begin(),s.begin()+1);
	int n=s.length();
	s="#"+s;
	for (int i=1;i<=n;i++)
	{
		if ((i%2==0 && (s[i]-'0')%2==0) || (i%2==1 && (s[i]-'0')%2==1)) continue;
		else 
		{
			cout<<"NO\n";
			return;
		} 
	}
	cout<<"YES\n";
}
int main()
{
	//freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		cin>>s;
		process();
	}
}
