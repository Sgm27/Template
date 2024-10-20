#include <bits/stdc++.h>
using namespace std;
int n=4,a[5];
void input()
{
	for (int i=1;i<=4;i++) cin>>a[i];
}
void process()
{
	for (int i=1;i<=n-2;i++)
		for (int j=i+1;j<=n-1;j++)
			for (int k=j+1;k<=n;k++) 
				if (a[i]+a[j]>a[k] && a[j]+a[k]>a[i] && a[i]+a[k]>a[j]) 
				{
					cout<<"TRIANGLE";
					return;
				}
	for (int i=1;i<=n-2;i++)
		for (int j=i+1;j<=n-1;j++)
			for (int k=j+1;k<=n;k++) 
				if (a[i]+a[j]==a[k] || a[k]+a[j]==a[i] || a[k]+a[i]==a[j]) 	
				{
					cout<<"SEGMENT";
					return;
				}
	cout<<"IMPOSSIBLE";
}
int main()
{
//	freopen("thu.inp","r",stdin);
	input();
	process();
}
