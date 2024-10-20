#include <bits/stdc++.h>
using namespace std;
int n,d[258],csd,sum;
int main()
{
	freopen("thu.inp","r",stdin);
	memset(d,0,sizeof(d));
	cin>>n;
	csd=1; sum=0;
	for (int i=1;i<=n;i++)
	{
		char x;
		cin>>x;
		d[x]++;
		if (d[x]==2)
		{
			sum+=(i-csd)*(i-csd+1)/2;
			csd=i;
			memset(d,0,sizeof(d));
			if (csd==n) 
			{
				sum++;
				break;
			}
		}
	}
	cout<<sum;
}
