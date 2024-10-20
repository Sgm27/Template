#include <bits/stdc++.h>
using namespace std;
void process(string s)
{
	if (next_permutation(s.begin(),s.end()))
	{
		for (char x : s) cout<<x;
		cout<<endl;
	}
	else cout<<"BIGGEST\n";
}
int main()
{
	freopen("thu.inp","r",stdin);
	int tc; cin>>tc;
	while (tc--)
	{
		int tt; string tmp;
		cin>>tt>>tmp;
		cout<<tt;
		process(tmp);
	}
}
