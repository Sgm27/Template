#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[500005],s[500005],tmp1,tmp2,mc,res;
bool ok=false;
void input()
{
	s[0]=0;
	cin>>n;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	if (s[n]%3==0)
	{
		ok=true;
		tmp1=(s[n]/3)*2;
	}
	mc=s[n]/3;
}
void process()
{
	long long tong = 0;
    if (s[n] % 3 == 0)
    {
        int dem = 0;
        for (int i = n - 1; i>0; i--)
        {
            if (s[i] == s[n] / 3)
            {
                tong = tong + dem;
            }
            if (s[i] == s[n] / 3 * 2)
            {
                dem++;
            }
        }
    }
    cout << tong << endl;
}
int main()
{
//	freopen("thu.inp","r",stdin);
	input();
	process();
}
