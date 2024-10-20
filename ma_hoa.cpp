#include <bits/stdc++.h>
using namespace std;
int d[256];
void process(string s)
{
	int Max=-1,cs;
	for (int i=65;i<=90;i++) d[i]=0;
	for (char x : s)
	{
		if (x>='A' && x<='Z') d[(int)(x)]++;
		if (d[(int)(x)]>Max)
		{
			Max=d[(int)(x)];
			cs=(int)(x);
		}
	}
	int dem=0;
	for (int i=0;i<s.length();i++) 
		if (d[(int)(s[i])]==Max) 
		{
			dem++;
			d[(int)(s[i])]=0;
		}
	if (dem>1) 
	{
		cout<<"NOT POSSIBLE\n";
		return;
	}
	int k;
	if (cs>=69) k=cs-69;
	else {
		k=21+1+(cs-65);
	}
	cout<<k<<" ";
	for (char x : s)
	{
		if (x==' ') 
		{
			cout<<x;
			continue;
		}
		if ((int)(x)-k>=65) cout<<(char)((int)(x)-k);
		else
		{
			int y=(int)(x)-k;
			int tmp=65-y;
			tmp=91-tmp;
			cout<<(char)(tmp);
		}
	}
	cout<<"\n";
}
int main()
{
	freopen("thu.inp","r",stdin);
	int tc;
	cin>>tc;
	cin.ignore();
	while (tc--)
	{
		string s;
		getline(cin,s);
		process(s);
	}
}
