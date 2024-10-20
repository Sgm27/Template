#include <bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("thu.inp","r",stdin);
	int tc; cin>>tc;
	cin.ignore();
	while (tc--)
	{
		string s;
		getline(cin,s);
		if (s=="dung") cout<<2<<endl;
		if (s=="nho hon") cout<<3<<endl;
		if (s=="lon hon") cout<<1<<endl;
	}
}
