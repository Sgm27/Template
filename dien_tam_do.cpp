#include <bits/stdc++.h>
using namespace std;
int n,st=-1,a[1005],cot=0,hang=-1,Min=1e9;
char res[1005][1000005];

void input()
{
	int sum=0;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		cot+=a[i];
		if (i%2) sum+=a[i];
		else sum-=a[i];
		st=max(st,sum);
		Min=min(Min,sum);
	}
	hang=st+abs(Min);
}
void process()
{
	int idx=0;
	for (int i=1;i<=n;i++) 
	{
		if (i%2)
		{
			for (int j=1;j<=a[i];j++)
				res[st--][++idx]='/';
			st++;
		}
		else
		{
			for (int j=1;j<=a[i];j++)
				res[st++][++idx]=(char)(92);
			st--;
		}
	}
	for (int i=1;i<=hang;i++)
	{
		for (int j=1;j<=cot;j++)
			if (res[i][j]=='/' || res[i][j]==(char)(92)) cout<<res[i][j];
		else cout<<" ";
		cout<<endl;
	}
}
int main()
{
	//freopen("thu.inp","r",stdin);
	input();
	process();
}
