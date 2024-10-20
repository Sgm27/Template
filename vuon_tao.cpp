#include <bits/stdc++.h>
using namespace std;
using db=double;
db xa,ya,xb,yb,xc,yc;
db kq;
void input()
{
	cin>>xa>>ya>>xb>>yb>>xc>>yc;
}
float dt(db xA,db yA,db xB,db yB,db xC,db yC)
{
	return 0.5*abs(xA*yB-xB*yA+xB*yC-xC*yB+xC*yA-xA*yC);
}
bool check(db xm,db ym)
{
	db dt1=dt(xm,ym,xa,ya,xb,yb);
	db dt2=dt(xm,ym,xa,ya,xc,yc);
	db dt3=dt(xm,ym,xb,yb,xc,yc);
	if (fabs(dt1+dt2+dt3-kq)<0.1) return 1;
	if (dt1==0 || dt2==0 || dt3==0) return 1;
	else return dt1+dt2+dt3==kq;
}
void process()
{
	kq=dt(xa,ya,xb,yb,xc,yc);
	cout<<fixed<<setprecision(1)<<kq<<endl;
	int tc,cnt=0;
	cin>>tc;
	while (tc--)
	{
		db a,b;
		cin>>a>>b;
		if (check(a,b)) cnt++;
	}
	cout<<cnt;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	input();
	process();
}
