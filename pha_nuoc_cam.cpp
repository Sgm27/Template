#include <bits/stdc++.h>
using namespace std;
int n;
double a[105];
void input()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
}
void process()
{
	double s=0;
	for (int i=1;i<=n;i++) s+=a[i];
	s/=n;
	cout<<fixed<<setprecision(12)<<s;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	input();
	process();
}
