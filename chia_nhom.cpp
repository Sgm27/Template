#include <bits/stdc++.h>
using namespace std;
int n,k,a[105],x[105],res=0,sum[105];
void input()
{
	sum[0]=0;
	cin>>n>>k;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
}
void process()
{
	int tmp=sum[x[1]];
	if (tmp!=sum[n]-sum[x[k]]) return;
	for (int i=2;i<=k;i++) 
		if (sum[x[i]]-sum[x[i-1]]!=tmp) return;
	res++;
}
void Try(int i)
{
	for (int j=x[i-1]+1;j<n;j++)
	{
		x[i]=j;
		if (i==k) process();
		else Try(i+1);
	}
}
int main()
{
	//freopen("thu.inp","r",stdin);
	input();
	if (k==1) 
	{
		cout<<1;
		return 0;
	}
	k--;
	x[0]=0;
	Try(1);
	cout<<res;
}
