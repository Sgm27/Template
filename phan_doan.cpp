#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct mang{
	ll x,y;
};
ll n;
mang a[200005];
void nhap()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
	}
}
bool cmp(mang a,mang b)
{
	if (a.x==b.x) return a.y>b.y;
	else return (a.x<b.x);
}
void process()
{
	sort(a+1,a+n+1,cmp);
//	for (int i=1;i<=n;i++)
//	{
//		cout<<a[i].x<<" "<<a[i].y<<endl;
//	}
	multiset<int> ms;
	for (int i=n;i>=1;i--)
	{
		ms.insert(a[i]);
		int n=0;
		for (int x : ms)
		{
			while (a[i]==x) 
		}
	}
}
int main()
{
	freopen("thu.inp","r",stdin);
	nhap();
	process();
}
