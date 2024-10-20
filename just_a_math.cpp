#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
	//freopen("thu.inp","r",stdin);
	int tc; cin>>tc;
	while (tc--)
	{
		ll a,b; 
		cin>>a>>b;
		string s="9";
		int dem=0;
		while (stoll(s)<=b) 
		{
			dem++;
			s+='9';
		}
		cout<<dem*a<<endl;
	}
}
