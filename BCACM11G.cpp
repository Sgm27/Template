#include <bits/stdc++.h>
using namespace std;
int n,k,a[105],res;
void input()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
}
void Try(int i,int k,int cnt)
{
	if (cnt==k) 
	{
		res++;
	}
	else 
	{
		for (int j=i+1;j<=n;j++) 
			if (a[i]<a[j]) Try(j,k,cnt+1);
	}
}
void process()
{
	res=0;
	for (int i=1;i<=n-k+1;i++) 
	{
		Try(i,k,1);
	}
	cout<<res<<endl;
}
int main()
{
	freopen("thu.inp","r",stdin);
	int tc; cin>>tc;
	while (tc--)
	{
		input();
		process();
	}
}
