#include <bits/stdc++.h>
using namespace std;
int n,a[105],b[105];
void input()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i]>>b[i];
}
bool check(int k)
{
	for (int i=1;i<=n;i++)
		if (k!=i && a[k]==b[i]) return true;
	return false;
}
void process()
{
	int cnt=0;
	for (int i=1;i<=n;i++)
		if (!check(i)) cnt++;
	cout<<cnt;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	input();
	process();
}
