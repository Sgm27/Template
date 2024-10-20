#include <bits/stdc++.h>
using namespace std;
int n,tt;
string s;
void process()
{
	cout<<tt<<" ";
	for (int i=0;i<s.length();i++)
		for (int j=1;j<=n;j++) cout<<s[i];
	cout<<endl;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc; cin>>tc;
	while (tc--)
	{
		cin>>tt>>n>>s;
		process();
	}
}
