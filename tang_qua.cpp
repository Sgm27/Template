#include <bits/stdc++.h>
using namespace std;
int n,a[105],kq[105];
void input()
{
	cin>>n;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
		kq[a[i]]=i;
	}
}
void process()
{
	for (int i=1;i<=n;i++) cout<<kq[i]<<" ";
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	process();
}

