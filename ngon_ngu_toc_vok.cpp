#include <bits/stdc++.h>
using namespace std;
string s;
set<string> se;
int n;
void input()
{
	cin>>s;
	n=s.length();
	s+="##";
}
void init()
{
	se.insert("c=");
	se.insert("c-");
	se.insert("dz=");
	se.insert("d-");
	se.insert("lj");
	se.insert("nj");
	se.insert("s=");
	se.insert("z=");
}
void process()
{
	init();
	string tmp1,tmp2;
	int i=0,cnt=0;
	while (i<n)
	{
		tmp1=""; tmp2="";
		for (int j=i;j<=i+1;j++) tmp1+=s[j]; 
		for (int j=i;j<=i+2;j++) tmp2+=s[j];
		if (se.count(tmp1)) 
		{
			cnt++;
			i+=2;
		} else if (se.count(tmp2))
		{
			cnt++;
			i+=3;
		} else 
		{
			cnt++;
			i++;
		}
	//	cout<<tmp1<<" "<<tmp2<<endl;
	}
	cout<<cnt;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	input();
	process();
}
