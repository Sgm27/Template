#include <bits/stdc++.h>
using namespace std;
int cnt=0;
struct mang{
	int gt1,gt2,cs;
};
bool cmp(mang a,mang b)
{
	return a.gt1<b.gt1;
}
void process(mang a[],int n)
{
//	cout<<"Case "<<cnt<<": ";
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++) cout<<a[i].gt1<<" "; cout<<endl;
	for (int i=1;i<=n;i++) cout<<a[i].gt2<<" "; cout<<endl;
	for (int i=1;i<=n;i++) cout<<a[i].cs<<" "; cout<<endl;
	for (int i=1;i<=n-1;i++)
		if (a[i].gt2>a[i+1].gt2) 
		{
//			cout<<a[i].cs;
			return;
		}
//	cout<<"agree\n";
}
int main()
{
	freopen("thu.inp","r",stdin);
	int n;
	while (cin>>n)
	{
		cnt++;
		mang a[n+5];
		for (int i=1;i<=n;i++) cin>>a[i].gt1;
		for (int i=1;i<=n;i++) cin>>a[i].gt2;
		for (int i=1;i<=n;i++) a[i].cs=i;
		process(a,n);
	}
}
