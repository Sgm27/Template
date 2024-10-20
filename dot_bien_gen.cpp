#include <bits/stdc++.h>
using namespace std;
int n,a[1000005],b[1000005];
string s;
void input()
{
	cin>>n>>s;
	s="#"+s;
}
void process()
{
	if (s[1]=='A') b[1]++; else a[1]++;
	for (int i=2;i<=n;i++)
		if (s[i]=='A')
		{
			a[i]=a[i-1];
			b[i]=min(a[i-1],b[i-1])+1;
		}
		else
		{
			b[i]=b[i-1];
			a[i]=min(a[i-1],b[i-1])+1;
		}
	cout<<min(a[n],b[n]+1);
}
int main()
{
//	freopen("thu.inp","r",stdin);
	input();
	process();
}
