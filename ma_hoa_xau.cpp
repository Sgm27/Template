#include <bits/stdc++.h>
using namespace std;
int d[125];
int main()
{
	freopen("thu.inp","r",stdin);
	int tc; cin>>tc;
	cin.ignore();
	while (tc--)
	{
		int res=0;
		memset(d,0,sizeof(d));
		string s,tmp=""; 
		getline(cin,s);
		for (int i=0;i<s.length();i++) 
			if (s[i]!=' ') 
			{
				d[tolower(s[i])]++;
				if (d[tolower(s[i])]==1) tmp+=tolower(s[i]);
			}
		for (int i=0;i<tmp.length();i++) 
			if (d[tmp[i]]>1) res+=d[tmp[i]];
		cout<<res<<" "<<tmp;
		cout<<endl;
	}
}
