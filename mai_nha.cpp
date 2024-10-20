#include <bits/stdc++.h>
using namespace std;
int n,a[5005],res,dinh;
void input()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
}
void process()
{
	int i=0;
	res=INT_MAX;
	while (i<n)
	{
		int tmp=0;
		i++; 
		if (dinh<i || dinh<=n-i) 
		{
			dinh=max(i,n-i+1);
			tmp=abs(dinh-a[i]);
		}
		for (int j=1;j<=n;j++) 
			if (j!=i)
		{
			tmp+=abs(a[j]-(dinh-abs(i-j)));
			cout<<dinh-abs(i-j)<<" ";
		}
		cout<<endl;
		res=min(res,tmp);
	}
	cout<<res;
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	process();
}
