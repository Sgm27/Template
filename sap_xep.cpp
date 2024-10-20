#include <bits/stdc++.h>
using namespace std;
int n,m,cnt_duong,cnt_am;
void input()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) 
	{
		int tmp;
		cin>>tmp;
		if (tmp==-1) cnt_am++;
		else cnt_duong++;
	}	
}
int main()
{
//	freopen("thu.inp","r",stdin);
	input();
	while (m--)
	{
		int x,y;
		cin>>x>>y;
		if (cnt_duong==0 || cnt_am==0 || (y-x+1)%2 || (y-x+1)/2>cnt_duong || (y-x+1)/2>cnt_am)
		{
			cout<<0<<endl;
			continue;
		}
		cout<<1<<endl;
	}
}
