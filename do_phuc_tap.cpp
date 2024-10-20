#include <bits/stdc++.h>
using namespace std;
int d[256],n,a[27];
string s;
int main()
{
	memset(d,0,sizeof(d));
//	freopen("thu.inp","r",stdin);
	cin>>s; 
	n=0;
	for (int i=0;i<s.length();i++) 
	{
		d[s[i]]++;
	}
	for (int i=97;i<=122;i++)
		if (d[i]!=0)
		{
			n++;
			a[n]=d[i];
		}
	sort(a+1,a+n+1,greater<int>());
//	for (int i=1;i<=n;i++) cout<<a[i]<<" "; cout<<endl;
	int res=0;
	while (n>2)
	{
		res+=a[n];
		n--;
	}
	cout<<res;
	return 0;
}

