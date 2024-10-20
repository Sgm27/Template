#include <bits/stdc++.h>
using namespace std;
int n,a[1005],tmp[1005];
void input()
{
	cin>>n;
	for (int i=1;i<=n;i++) a[i]=i;
}
void dq(int a[],int i)
{
	if (i==1) return;
	else 
	{
		swap(a[i],a[i-1]);
		dq(a,i-1);
	}
}
bool check(int a[],int n)
{
	for (int i=1;i<=n-1;i++) 
	if (a[i]>a[i+1]) return false;
	return true;
}
void process()
{
	while (next_permutation(a+1,a+1+n))
	{
		for (int i=1;i<=n;i++) tmp[i]=a[i];
		dq(tmp,n);
		if (check(tmp,n))
		{
			for (int i=1;i<=n;i++) cout<<a[i]<<" ";
			return;
		}
	}
}
int main()
{
	freopen("thu.inp","r",stdin);
	freopen("thu.out","w",stdout);
	input();
	process();
}
