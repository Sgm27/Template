#include <bits/stdc++.h>
using namespace std;
int res[35];
void init()
{
	int tmp,tmp1,tmp2;
	res[0]=0;
	res[1]=1;
	res[2]=4;
	for (int i=3;i<=30;i++)
	{
		if (i%2==0)
		{
			tmp=i/2;
			res[i]=tmp*i;
		}
		else
		{
			tmp1=i/2+1;
			tmp2=tmp1-1;
			res[i]=tmp1*tmp1+tmp2*tmp2;
		}
	}
}
int main()
{
//	freopen("thu.inp","r",stdin);
	init();
	int tc; cin>>tc;
	while (tc--)
	{
		int n; cin>>n;
		cout<<res[n]<<endl;
	}
}
