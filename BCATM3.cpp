#include <bits/stdc++.h>
using namespace std;
int d[100];
void init()
{
	d[1]=500; d[2]=200; d[3]=100; d[4]=50; d[5]=20; d[6]=10; d[7]=5; d[8]=2; d[9]=1;
}
void process(int n)
{
	int idx=1,res=0;
	while (n)
	{
		if (n>=d[idx])
		{
			n-=d[idx];
			res++;
		}
		else idx++;
	}
	cout<<res<<endl;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	init();
	int tc;
	cin>>tc;
	while (tc--)
	{
		int n;
		cin>>n;
		process(n);
	}
}

