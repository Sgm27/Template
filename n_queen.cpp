#include <bits/stdc++.h>
using namespace std;
bool xuoi[1100],nguoc[1100],cot[11];
int n,cnt=0;
void Try(int i)
{
	for (int j=1;j<=n;j++)
		if (cot[j] && xuoi[i-j+n] && nguoc[i+j-1])
		{
			cot[j]=false;
			xuoi[i-j+n]=false;
			nguoc[i+j-1]=false;
			if (i==n)
			{
				cnt++;
			}
			else Try(i+1);
			cot[j]=true;
			xuoi[i-j+n]=true;
			nguoc[i+j-1]=true;
		}
}
int main()
{
	memset(cot,true,sizeof(cot));
	memset(xuoi,true,sizeof(xuoi));
	memset(nguoc,true,sizeof(nguoc));
//	freopen("thu.inp","r",stdin);
	cin>>n;
	Try(1);
	cout<<cnt;
}
