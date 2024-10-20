#include <bits/stdc++.h>
using namespace std;
int n,a[1005],b[1005];
void input()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) cin>>b[i];
}
void process()
{
	int hieu=a[3]-a[2];
	int tong=b[3];
	int x=(tong+hieu)/2;
	int r1=a[3]-x;
	cout<<r1<<" ";
	for (int i=2;i<=n;i++)
		if (i==3) cout<<x<<" ";
		else cout<<a[i]-r1<<" ";
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	process();
}
