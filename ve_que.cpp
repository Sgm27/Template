#include <bits/stdc++.h>
using namespace std;
int n,a[5][20];
void input()
{
	cin>>n;
}
void process()
{
	string s="+------------------------+";
	for (int i=1;i<=4;i++)
			for (int j=1;j<=11;j++) a[i][j]=1;
	bool ok=true;
	int i=1,j=1;
	while (n>0)
	{
		n--;
		if (i==5) 
		{
			i=1;
			j++;
		}
		if (i==3 && ok) {
			a[i][j]=0;
			ok=false;
		}
		else 
		if (i==3 && !ok) i++;
		a[i][j]=0;
		i++;
	}
	cout<<s<<endl;
	for (int i=2;i<=11;i++) a[3][i]=-1;
	int dem=1;
	while (dem<=4)
	{
		cout<<"|";
		for (int j=1;j<=11;j++) 
		{
			if (a[dem][j]==0) cout<<"O.";
			if (a[dem][j]==-1) cout<<"..";
			if (a[dem][j]==1) cout<<"#.";
		}
		if (dem==1) cout<<"|D|)";
		else if (dem==2 || dem==4) cout<<"|.|"; else cout<<"..|";
		if (dem==4) cout<<")";
		cout<<endl;
		dem++;
	}
	cout<<s;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	input();
	process();
}
