#include <bits/stdc++.h>
using namespace std;
char a[5][5];
void input()
{
	for (int i=1;i<=4;i++)
		for (int j=1;j<=4;j++) cin>>a[i][j];
}
bool check(int i,int j)
{
	int sum1=0,sum2=0;
	if (a[i][j]=='#') sum1++; else sum2++;
	if (a[i+1][j]=='#') sum1++; else sum2++;
	if (a[i][j+1]=='#') sum1++; else sum2++;
	if (a[i+1][j+1]=='#') sum1++; else sum2++;
	if (sum1==1 || sum1==0 || sum2==1 || sum2==0) return true;
	return false;
}
void process()
{
	for (int i=1;i<=3;i++)
		for (int j=1;j<=3;j++)
			if (check(i,j)) 
			{
				cout<<"YES";
				return;
			}
	cout<<"NO";
}
int main()
{
//	freopen("thu.inp","r",stdin);
	input();
	process();
}
