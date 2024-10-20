#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("tach_xau.inp","r",stdin);
	getline(cin,s);
	stringstream ss(s);
	string tmp;
	while (ss >> tmp)
	{
		cout<<tmp<<endl;
	}
	return 0;
}
