#include <bits/stdc++.h>
using namespace std;
bool cmp(char a,char b)
{
	return a>b;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		string s="",a,b,c;
		cin>>a>>b>>c;
		s=a+b+c;
		sort(s.begin(),s.end()+1,cmp);
		cout<<s<<endl;
	}
}
