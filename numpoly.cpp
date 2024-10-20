#include <bits/stdc++.h>
using namespace std;
int n;
void nhap()
{
	cin>>n;
}
int tohop(int n,int k)
{
	if (k==0 || k==n) return 1;
	if (k==1) return n;
	return tohop(n-1,k-1)+tohop(n-1,k);
}
void process()
{
	if (n<=3) 
	{
		cout<<0;
		return;
	}
	cout<<tohop(n,4);
}
int main()
{
	//freopen("thu.inp","r",stdin);
	nhap();
	process();
}
