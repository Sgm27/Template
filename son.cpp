#include <bits/stdc++.h>
using namespace std;
struct thongtin{
	string name,ngaysinh;
	double mon1,mon2,mon3;
	int sum()
	{
		return (mon1+mon2+mon3);	
	}
};
int main()
{
	freopen("son.inp","r",stdin);
	thongtin ds;
	getline(cin,ds.name);
	getline(cin,ds.ngaysinh);
	cin>>ds.mon1>>ds.mon2>>ds.mon3;
	cout<<ds.name<<" "<<ds.ngaysinh<<" "<<ds.sum();
}
