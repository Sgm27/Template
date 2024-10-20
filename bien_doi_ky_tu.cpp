#include <bits/stdc++.h>
using namespace std;
void process(string s)
{
	if (next_permutation(s.begin(),s.end())) cout<<s<<endl;
	else cout<<"BIGGEST\n";
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc; cin>>tc;
	string s;
	while (tc--)
	{
		cin>>s;
		process(s);
	}
}
