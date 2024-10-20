#include <bits/stdc++.h>
using namespace std;
int n;
string timein,timeout;
struct mang{
	string uname,pass,name;
	int gio,phut;
};
mang a[25];
void time(int k,string time1,string time2)
{
	string x1,x2;
	x1=time1.substr(3,2);
	x2=time2.substr(3,2);
	int g=0;
	if (stoi(x2)>=stoi(x1)) a[k].phut=stoi(x2)-stoi(x1);
	else 
	{
		a[k].phut=stoi(x2)+60-stoi(x1);
		g=1;
	}
	x1=time1.substr(0,2);
	x2=time2.substr(0,2);
	a[k].gio=stoi(x2)-stoi(x1)-g;
}
bool cmp(mang a,mang b)
{
	if (a.gio!=b.gio) return a.gio>b.gio;
	else 
	{
		if (a.phut!=b.phut) return a.phut>b.phut;
		else return a.uname<b.uname;
	}
}
int main()
{
//	freopen("thu.inp","r",stdin);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i].uname;
		cin>>a[i].pass;
		cin.ignore();
		getline(cin,a[i].name);
		cin>>timein>>timeout;
		time(i,timein,timeout);
	}
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=n;i++) 
		cout<<a[i].uname<<" "<<a[i].pass<<" "<<a[i].name<<" "<<a[i].gio<<" gio "<<a[i].phut<<" phut"<<endl;
}
