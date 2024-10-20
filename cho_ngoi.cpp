#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main()
{
//	freopen("thu.inp","r",stdin);
	cin>>n>>s;
	int i=0,res=0;
	while (i<n)
	{
		res++;
		if (s[i]=='L') i+=2;
		else i++;
	}
	cout<<min(n,res+1);
}
