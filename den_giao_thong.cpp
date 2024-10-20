#include <bits/stdc++.h>
using namespace std;
int n,l;
struct mang{
	int cs,r,g;
	int sum()
	{
		return r+g;
	}
};
mang a[105];
void input()
{
	cin>>n>>l;
	for (int i=1;i<=n;i++) cin>>a[i].cs>>a[i].r>>a[i].g;
}
void process()
{
	int time=0;
	a[0].cs=0;
	for (int i=1;i<=n;i++)
	{
		time+=(a[i].cs-a[i-1].cs);
		int tmp=time%a[i].sum();
		if (tmp<a[i].r) time+=(a[i].r-tmp);
	}
	time+=(l-a[n].cs);
	cout<<time;
}
int main()
{
	//freopen("thu.inp","r",stdin);
	input();
	process();
}
