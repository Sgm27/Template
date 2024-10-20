#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
// #define int long long
#define pii pair<int,int>
// const int MOD=1e9+7,INF=4e18;
#define maxn 
int cnt = 0;
class PhanSo {
    public :
    long long tu,mau;
    PhanSo(long long _tu,long long _mau)
    {
        tu = _tu;
        mau = _mau;
    }
    PhanSo() {}
    friend istream &operator>>(istream &in,PhanSo &x)
    {
        cin>>x.tu>>x.mau;
        return in;
    }
    void rutgon()
    {
        long long G = __gcd(tu,mau);
        tu /= G;
        mau /= G;
    }
    friend ostream &operator<<(ostream &out,PhanSo x)
    {
        cout<<x.tu<<"/"<<x.mau;
        return out;
    }
    friend PhanSo operator+(const PhanSo a,const PhanSo b)
    {
        PhanSo ans(1,1);
        ans.tu = a.tu * b.mau + a.mau * b.tu;
        ans.mau = a.mau * b.mau;
        ans.rutgon();
        return ans;
    }
    friend PhanSo operator*(const PhanSo a,const PhanSo b)
    {
        PhanSo ans(1,1);
        ans.tu = a.tu * b.tu;
        ans.mau = a.mau * b.mau;
        ans.rutgon();
        return ans;
    }
};
void process(PhanSo A,PhanSo B)
{
    PhanSo C = (A + B) * (A + B);
    PhanSo D = A * B * C;
    cout<<C<<" "<<D<<"\n";
}
int main() {
    freopen("thu.inp","r",stdin);
	int t;
	cin >> t;
	while (t--) {
		PhanSo A;
		PhanSo B;
		cin >> A.tu >> A.mau >> B.tu >> B.mau;
		process(A, B);
	}
}