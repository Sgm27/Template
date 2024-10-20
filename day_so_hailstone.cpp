#include <bits/stdc++.h>
using namespace std;
void process(int n)
{
	int i=1;
	long long res=1,cs=n;;
	while (cs!=1)
	{
		if (cs%2) cs=cs*3+1;
		else cs/=2;
		res++;
	}
	cout<<res<<endl;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	int n;
	while (cin>>n)
	{
		if (n==0) return 0;
		process(n);
	}
}
