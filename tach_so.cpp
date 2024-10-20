#include <bits/stdc++.h>
using namespace std;
vector<string> v;
bool cmp(string a,string b)
{
	if (a.length()!=b.length()) return a.length()<b.length();
	else return a<b;
}
void process()
{
	int n;
	cin>>n;
	while (n--)
	{
		string s;
		cin>>s;
		int i=0;
		while (i<s.length())
		{
			if (s[i]>='0' && s[i]<='9')
			{
				string tmp="";
				while (s[i]>='0' && s[i]<='9') 
				{
					tmp+=s[i];
					i++;
				}
				if (tmp=="0") v.push_back(tmp);
				else 
				{
					while (tmp[0]=='0' && tmp.size()!=1) tmp.erase(tmp.begin());
					v.push_back(tmp);
				}
			}
			else i++;
		}
	}
	sort(v.begin(),v.end(),cmp);
	for (string k : v) cout<<k<<"\n";
}
int main()
{
	//freopen("thu.inp","r",stdin);
	process();
}
