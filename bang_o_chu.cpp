#include <bits/stdc++.h>
using namespace std;
int n,m;
char a[25][25];
bool ngang[25][25],doc[25][25];
vector<string> v;
void input()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) cin>>a[i][j];
}
void init()
{
	for (int i=1;i<=n;i++) a[i][m+1]='#';
	for (int i=1;i<=m;i++) a[n+1][i]='#';
}
void process()
{
	memset(ngang,true,sizeof(ngang));
	memset(doc,true,sizeof(doc));
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			if (ngang[i][j])
			{
				int k=j,cnt=0;
				string tmp="";
				while (1)
				{
					if (a[i][k]=='#') break;
					cnt++;
					ngang[i][k]=false;
					tmp+=(a[i][k]);
					k++;
				}
				if (cnt>=2) v.push_back(tmp);
			}
			if (doc[i][j])
			{
				int k=i,cnt=0;
				string tmp="";
				while (1)
				{
					if (a[k][j]=='#') break;
					cnt++;
					doc[k][j]=false;
					tmp+=(a[k][j]);
					k++;
				}
				if (cnt>=2) v.push_back(tmp);
			}
		}
	string res=v[0];
	for (string x : v) if (x<res) res=x;
	cout<<res;
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	init();
	process();
}
