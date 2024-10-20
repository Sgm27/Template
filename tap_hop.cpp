#include <bits/stdc++.h>
using namespace std;
int n,k,s,sum=0,res=0,x[150];
void Try(int i)
{
	if (sum>s) return;
	for (int j=x[i-1]+1;j<=n;j++)
		if (j<=s-sum)
	{
		x[i]=j;
		sum+=j;
		if (i==k && sum==s) res++;
		else Try(i+1);
		sum-=j;
	}
}
int main()
{
//	freopen("thu.inp","r",stdin);
	while (1)
	{
		sum=0; res=0;
		cin>>n>>k>>s;
		if (n==0 && k==0 && s==0) return 0;
		Try(1);
		cout<<res<<endl;
	}
}
