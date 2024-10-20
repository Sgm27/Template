#include <bits/stdc++.h>
using namespace std;
int n;
char a[35][35];
void input()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) cin>>a[i][j];
}
bool check(int i,int j)
{
	if (a[i][j]=='.') return false;
	if (a[i][j]==a[i][j+1] && a[i][j]==a[i][j+2]) return true;
	if (a[i][j]==a[i+1][j] && a[i][j]==a[i+2][j]) return true;
	if (a[i][j]==a[i+1][j+1] && a[i][j]==a[i+2][j+2]) return true;
	if (i>=3 && a[i][j]==a[i-1][j+1] && a[i][j]==a[i-2][j+2]) return true;
	return false;
}
void process()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) 
			if (check(i,j)) 
			{
				cout<<a[i][j];
				return;
			}
	cout<<"ongoing";
}
int main()
{
	freopen("thu.inp","r",stdin);
	memset(a,'-',sizeof(a));
	input();
	process();
}
