#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100005],b[100005];
void input()
{
	string s1,s2;
	cin>>s1>>s2;
	n=s1.length()-1; m=s2.length()-1;
	for (int i=0;i<=n;i++) a[i+1]=s1[i]-'0';
	for (int i=0;i<=m;i++) b[i+1]=s2[i]-'0';
}
void process()
{
	n++; m++;
	sort(b+1,b+1+m,greater<int>());
	int i=1,j=1;
	while (i<=n && j<=m)
	{
		if (a[i]<b[j]) 
		{
			a[i]=b[j];
			j++;
			i++;
		}
		else i++;
	}
	for (int i=1;i<=n;i++) cout<<a[i];
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	process();
}
