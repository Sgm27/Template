#include <bits/stdc++.h>
using namespace std;
char x;
string s;
int d[257];
void input()
{
	cin>>x>>s;
}
void process()
{
	int n=s.length()-1;
	string st="#qwertyuiopqasdfghjkl;azxcvbnm,./z";
	for (int i=0;i<=257;i++) d[i]=-1;
	for (int i=1;i<=st.length()-1;i++)
		if (d[st[i]]==-1) 
		{
			d[st[i]]=i;
		}
	if (x=='L')
	{
		for (int i=0;i<=n;i++) cout<<st[d[s[i]]+1];
	}
	else 
	{
		for (int i=0;i<=n;i++) cout<<st[d[s[i]]-1];
	}
}
int main()
{
	freopen("thu.inp","r",stdin);
	input();
	process();
}
