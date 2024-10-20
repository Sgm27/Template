#include <bits/stdc++.h>
using namespace std;
string a[10005];
bool cmp(string a,string b)
{
	if (a.length()!=b.length()) return a.length()<b.length();
	else return a<b;
}
void process(int n,string a[])
{
	sort(a+1,a+1+n,cmp);
	set<string> se;
	string s,tmp="";
	for (int i=1;i<=n;i++)
	{
		tmp="";
		s=a[i];
		for (int j=0;j<s.length();j++)
		{
			tmp+=s[j];
			if (se.count(tmp)) 
			{
				cout<<"NO\n";
				return;
			}
		}
		se.insert(tmp);
	}
	cout<<"YES\n";
}
int main()
{
	freopen("thu.inp","r",stdin);
	int tc; cin>>tc;
	while (tc--)
	{
		int n; cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i];
		process(n,a);
	}
}

