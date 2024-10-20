#include <bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		double n,l,m;
		cin>>n>>l>>m;
		double tmp=log(m/n*1.0)/log(1.0+l*0.01);
		cout<<(int)(tmp)+1<<endl;
	}
}
