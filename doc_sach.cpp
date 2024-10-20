#include <bits/stdc++.h>
using namespace std;
int n,k,kq[10005];
struct mang{
	int gt,cs;
};
mang a[10005];
void input()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i].gt;
		a[i].cs=i;
	}
}
bool cmp(mang a,mang b)
{
	if (a.gt!=b.gt) return a.gt>b.gt;
	else return a.cs<b.cs;
}
void process()
{
	int Min=INT_MAX;
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=k;i++) 
	{
		kq[i]=a[i].cs;
		Min=min(Min,a[i].gt);
	}
	sort(kq+1,kq+1+k);
	cout<<Min<<endl;
	for (int i=1;i<=k;i++) cout<<kq[i]<<" ";
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	process();
}
