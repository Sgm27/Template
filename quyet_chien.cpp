#include <bits/stdc++.h>
using namespace std;
int n,a[200005],b[200005];
void input()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>b[i];
	for (int i=1;i<=n;i++) cin>>a[i];
}
void process()
{
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	int dem=0;
	int i=1,j=1;
	while (i<=n && j<=n)
	{
		if (a[i]>b[j]) 
		{
			dem++;
			i++; j++;
		}
		else i++;
	}
	cout<<dem;
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	process();
}
