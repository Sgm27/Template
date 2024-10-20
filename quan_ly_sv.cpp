#include <bits/stdc++.h>
using namespace std;
int n,m,k;
struct SinhVien{
	string masv,hoten,lop;
	double tbc;
	void nhap()
	{
		cin>>masv;
		cin.ignore();
		getline(cin,hoten);
		cin>>lop;
	}
};
struct MonHoc{
	string mamh,tenmh;
	int sotc;
	void nhap()
	{
		cin>>mamh;
		cin.ignore();
		getline(cin,tenmh);
		cin>>sotc;
	}
};
MonHoc MH[1005];
SinhVien SV[1005];
int check(string x)
{
	for (int i=1;i<=n;i++) 
		if (MH[i].mamh==x) return i;
	return 0;
}
int main()
{
	freopen("quan_ly_sv.inp","r",stdin);
	cin>>n>>m;
	cin.ignore();
	for (int i=1;i<=n;i++) MH[i].nhap();
	for (int i=1;i<=m;i++)
	{
		double sum=0,SoTC=0;
		SV[i].nhap();
		cin>>k;
		cin.ignore();
		for (int j=1;j<=k;j++)
		{
			string x;
			cin>>x;
			cin.ignore();
			int cs=check(x);
			if (!cs) cout<<"Ma MH khong hop le\n";
			else
			{
				SoTC+=MH[cs].sotc;
				double diemcc,diemkt,diemthi;
				cin>>diemcc>>diemkt>>diemthi;
				cin.ignore();
				sum+=(0.1*diemcc+0.2*diemkt+0.7*diemthi)*MH[cs].sotc;
			}
		}
		SV[i].tbc=(double)(sum/SoTC);
	}
	for (int i=1;i<=m;i++)
	{
		if (SV[i].tbc>7.0) cout<<SV[i].hoten<<endl;
	}
