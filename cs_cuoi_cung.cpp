#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("thu.inp","r",stdin);
	int tc; cin>>tc;
	while (tc--)
	{
		string s;
		cin>>s;
		while (s.length()!=1)
		{	
			int sum=0;
			for (char x : s) sum+=(x-'0');
			s=to_string(sum);
		}
		cout<<s<<endl;
	}
}
