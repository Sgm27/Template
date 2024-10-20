#include <bits/stdc++.h>
using namespace std;
int a[15];
string s;
void input()
{
	cin>>s;
}
void process()
{
	string tmp=s;
	bool ok=false;
	for (int i=0;i<=s.length()-2;i++) 
		if (s[i]>s[i+1]) ok=true;
	if (!ok)
	{
		cout<<0;
		return;
	}
	sort(tmp.begin(),tmp.end());
	bool check=false;
	while (1)
	{
		int cs=0;
		for (int i=0;i<tmp.length();i++)
			{
				if (tmp[i]>s[cs]) 
				{
					cout<<tmp[i];
					tmp.erase(tmp.begin()+i,tmp.begin()+i+1);
					cout<<tmp;
					return;
				}
				if (tmp[i]==s[cs])
			}
	}
}
