#include <bits/stdc++.h>
using namespace std;
struct mang{
	string ten;
	int ngay,thang,nam;
};
int n;
mang a[105];
void index()
{
	cin>>n; 	
	cin.ignore();
	for (int i=1;i<=n;i++)
	{
		string s; int dem=0;
		getline(cin,s);
		stringstream ss(s);
		string token;
		while (ss >> token)
		{
			dem++;
			if (dem==1) a[i].ten=token;
			if (dem==2) a[i].ngay=stoi(token);
			if (dem==3) a[i].thang=stoi(token);
			if (dem==4) a[i].nam=stoi(token);
		}
	}
//	for (int i=1;i<=n;i++) cout<<a[i].ten<<" "<<a[i].ngay<<" "<<a[i].thang<<" "<<a[i].nam<<endl;
//	cout<<"==================================================="<<endl;
}
bool cmp(mang a,mang b)
{
	if (a.nam!=b.nam) return a.nam<b.nam;
	else 
	{
		if (a.thang!=b.thang) return a.thang<b.thang;
		else
		{
			if (a.ngay!=b.ngay) return a.ngay<b.ngay;
		}
	}
}
void process()
{
	sort(a+1,a+1+n,cmp);
	cout<<a[n].ten<<endl<<a[1].ten;
}
int main()
{
	//freopen("thu.inp","r",stdin);
	index();
	process();
}
