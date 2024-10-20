#include <bits/stdc++.h>
using namespace std;
int l[1005],s;
void init()
{
	l[1]=1;
	l[2]=2;
	for (int i=3;i<=1005;i++)
	{
		l[i]=1;
		for (int j=1;j<=i/2;j++) l[i]+=l[j];
	}
}
int main()
{
	freopen("thu.inp","r",stdin);
	init();
	int tc,cnt=0; 
	cin>>tc;
	while (tc--)
	{
		cnt++;
		int n; cin>>n;
		cout<<cnt<<" "<<l[n]<<endl;
	}
}
