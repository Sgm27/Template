#include <bits/stdc++.h>
using namespace std;
int n;
void input()
{
	cin>>n;
}
void process()
{
	int cnt=1;
	int damge=1;
	while (n>0)
	{
		cnt++;
		damge+=cnt;
		n-=damge;
	}
	cout<<cnt-1;
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	process();
}
