#include <bits/stdc++.h>
using namespace std;
void process(string s)
{
	for (int i=s.length()-1;i>0;i--)
	{
		if (s[i]>='5') s[i-1]++;
		s[i]='0';
	}
	if (s[0]>'9') 
	{
		s[0]='0';
		cout<<"1"<<s<<endl;
	}
	else cout<<s<<endl;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		string x;
		cin>>x;
		process(x);
	}
}
