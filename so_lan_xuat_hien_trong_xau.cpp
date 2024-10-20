#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	//   freopen("thu.inp","r",stdin);
	//   freopen("thu.out","w",stdout);
	int tc; cin>>tc;
	cin.ignore();
	while (tc--)
	{
		int cnt=0;
		string s;
		char x;
		cin>>x;
		cin.ignore();
		getline(cin,s);
		for (char k : s)
			if (k==x) cnt++;
		cout<<cnt<<"\n";
	}
}

