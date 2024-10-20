#include <bits/stdc++.h>
using namespace std;
bool check[105];
int n;
void process()
{
	memset(check,true,sizeof(check));
	for (int i=2;i<=n;i++)
	{
		for (int j=1;j<=n;j++) 
			if (j%i==0)
			{
				if (check[j]) check[j]=false;
				else check[j]=true;
			}
	}
	int cnt=0;
	for (int i=1;i<=n;i++) 
		if (check[i]) cnt++;
	cout<<cnt<<endl;
}
int main()
{
	//freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	while (tc--) 
	{
		cin>>n;
		process();
	}
}
