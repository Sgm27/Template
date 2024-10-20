#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 
class DoanhNghiep{
    public :
    string ma,ten;
    int ssv;
    DoanhNghiep ()
    {
        ma = ten = "";
        ssv = 0;
    }
    friend istream &operator>>(istream &in,DoanhNghiep &x)
    {
        cin>>x.ma;
        cin.ignore();
        getline(cin,x.ten);
        cin>>x.ssv;
        return in;
    }
    friend ostream &operator<<(ostream &out,DoanhNghiep &x)
    {
        cout<<x.ma<<" "<<x.ten<<" "<<x.ssv<<"\n";
        return out;
    }
    friend bool operator<(const DoanhNghiep a,const DoanhNghiep b)
    {
        if (a.ssv != b.ssv) return a.ssv > b.ssv;
        return a.ma < b.ma;
    }
};
DoanhNghiep a[100005];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n; cin>>n;
    FOR(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    int q; cin>>q;
    while (q--)
    {
        int l,r; cin>>l>>r;
        cout<<"DANH SACH DOANH NGHIEP NHAN TU "<<l<<" DEN "<<r<<" SINH VIEN:\n";
        FOR(i,1,n) 
            if (a[i].ssv >= l && a[i].ssv <= r) cout<<a[i];
    }
}
