#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,s;
struct mang{
	ll sm,tt;
};
mang a[100005];
void input()
{
	cin>>n>>s;
	for (int i=1;i<=n;i++) cin>>a[i].sm>>a[i].tt;
}
bool cmp(mang a,mang b)
{
	if (a.sm!=b.sm) return a.sm<b.sm;
	else return a.tt>b.tt;
}
void process()
{
	sort(a+1,a+1+n,cmp);
	int i=1;
	while (i<=n)
	{
		if (s<=a[i].sm) 
		{
			cout<<"NO";
			return;
		}
		else 
		{
			s+=a[i].tt;
		}
		i++;
	}
	cout<<"YES";
}
int main()
{
//	freopen("thu.inp","r",stdin);
	input();
	process();
}
