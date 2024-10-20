#include <bits/stdc++.h>
using namespace std;
int n,k,a[45],d[45],tmp[45];
void process()
{
	memset(d,0,sizeof(d));
	for (int i=1;i<=n;i++) tmp[i]=a[i];
	if (!next_permutation(a+1,a+1+n)) cout<<k<<endl;
	else
	{
		for (int i=1;i<=n;i++) d[a[i]]++;
		for (int i=1;i<=n;i++) d[tmp[i]]--;
		int res=0;
		for (int i=1;i<=n;i++) res+=d[a[i]];
		cout<<res<<endl;
	}
}
int main()
{
	freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--)
	{
		cin>>n>>k;
		n=k;
		for (int i=1;i<=n;i++) cin>>a[i];
		process();
	}
}
