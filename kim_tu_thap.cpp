#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	//freopen("thu.inp","r",stdin);
	cin>>n;
	bool ok=true;
	int i=1,res;
	while (ok)
	{
		res+=i*(i+1)/2;
		if (res>n) ok=false;
		else i++;
	}
	cout<<i-1;
}
