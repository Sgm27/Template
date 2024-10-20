#include <bits/stdc++.h>
using namespace std;
int a,c,b,d;
int dd[2005];
void input()
{
	cin>>a>>b>>c>>d;
}
void init()
{
	for (int i=0;i<=1000;i+=(a+b))
		for (int j=i+1;j<=i+a;j++) dd[j]++;
	for (int i=0;i<=1000;i+=(c+d))
		for (int j=i+1;j<=i+c;j++) dd[j]++;
}
void process()
{
	init();
	int x;
	while (cin>>x) 
		if (dd[x]==2) cout<<"both\n";
	else	if (dd[x]==1) cout<<"one\n";
	else	if (dd[x]==0) cout<<"none\n";	
}
int main()
{
	memset(dd,0,sizeof(dd));
//	freopen("thu.inp","r",stdin);
	input();
	process();
}
