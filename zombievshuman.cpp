#include <bits/stdc++.h>
using namespace std;
void process(string s)
{
	s+="~";
	int zombie=0;
	int cs=0,nguoi=0;
	while (cs<s.length()-1)
	{
		int i=cs;
		if ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
		{
			while ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) i++;
			zombie=max(zombie,i-cs);
			cs=i;
		}
		else if (s[i]=='(')
		{
			while (s[i]!=')')
			{
				i++;
				if ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
				{
					while ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) i++;
					nguoi++;
				}
			}
			if (s[i]==')') cs=i;
		}
		else cs++;
	}
	cout<<zombie<<" "<<nguoi<<endl;
}
int main()
{
	freopen("thu.inp","r",stdin);
	int tc; cin>>tc;
	while (tc--)
	{
		string s;
		cin>>s;
		process(s);
	}
}
