#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,a[100005],s[100005],sum=0;
void input()
{
	cin>>n;
	s[0]=0;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	sum=s[n];
}
void process()
{
	if (a[1]>sum-a[1]) 
	{
		cout<<"1 "<<n-1;
		return;
	}
	if (a[n]>sum-a[n])
	{
		cout<<n-1<<" 1";
		return;
	}
	ll time1=0,time2=1,i=1;
	while (time1<time2)
	{
		i++;
		time1=s[i-1];
		time2=sum-s[i-1]-a[i];
	}
	if (time1==time2) 
	{
		cout<<i<<" "<<n-i;
		return;
	}
	else cout<<i-1<<" "<<n-i+1;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	input();
	process();
}
