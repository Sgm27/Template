#include <bits/stdc++.h>
using namespace std;
using ld=long double;
ld x[105],y[105];
int n;
void process()
{
	if (n==1) 
	{
		cout<<"1\n";
		return;
	}
	int Max=-1000000000;
	for (int i=1;i<=n-1;i++)
		for (int j=i+1;j<=n;j++)
		{
			int cnt=0;
			ld tx=(x[i]+x[j])/2;
			ld ty=(y[i]+y[j])/2;
			ld bk=sqrt((x[i]-tx)*(x[i]-tx)+(y[i]-ty)*(y[i]-ty));
			for (int l=1;l<=n;l++) 
			{
				ld tmp=sqrt((x[l]-tx)*(x[l]-tx)+(y[l]-ty)*(y[l]-ty));
				if (tmp==bk) cnt++;
			}
			Max=max(Max,cnt);
		}
	cout<<Max<<endl;
}
int main()
{
	// freopen("thu.inp","r",stdin);
	while (cin>>n)
	{
		if (n==0) return 0;
		for (int i=1;i<=n;i++) cin>>x[i]>>y[i];
		process();
	}
}