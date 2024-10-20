#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
// #define int long long
#define pii pair<int,int>
// const int MOD=1e9+7,INF=4e18;
#define maxn 
int kh = 0,mh = 0;
class KhachHang;
class MatHang;
class HoaDon;
map<string,KhachHang> posKH;
map<string,MatHang> posMH;
class KhachHang{
    public :
    string ma,ten,gt,ns,dc;
    KhachHang()
    {
        ma = ten = gt = ns = dc = "";
    }
    friend istream &operator>>(istream &in,KhachHang &x)
    {
        kh++;
        string t = to_string(kh);
        x.ma = "KH" + string(3 - t.size(),'0') + t;
        scanf("\n");
        getline(cin,x.ten);
        cin>>x.gt>>x.ns;
        cin.ignore();
        getline(cin,x.dc);
        posKH[x.ma] = x;
        return in;
    }
    friend ostream &operator<<(ostream &out,KhachHang x)
    {

        return out;
    }
};

class MatHang{
    public :
    string ma,ten,donvi;
    int giamua,giaban;
    MatHang()
    {
        donvi = ma = ten = "";
        giamua = giaban = 0;
    }
    friend istream &operator>>(istream &in,MatHang &x)
    {
        mh++;
        string t = to_string(mh);
        x.ma = "MH" + string(3 - t.size(),'0') + t;
        cin.ignore();
        getline(cin,x.ten);
        cin>>x.donvi>>x.giamua>>x.giaban;
        posMH[x.ma] = x;
        return in;
    }
};
int hd = 0;
class HoaDon{
    public :
    string makh,mamh,ma;
    int sl,loinhuan;
    HoaDon()
    {
        makh = mamh = "";
        sl = 0;
    }
    friend istream &operator>>(istream &in,HoaDon &x)
    {
        hd++;
        cin>>x.makh>>x.mamh>>x.sl;
        string t = to_string(hd);
        x.ma = "HD" + string(3 - t.size(),'0') + t;
        x.loinhuan = (posMH[x.mamh].giaban - posMH[x.mamh].giamua) * x.sl;
        return in;
    }
    friend ostream &operator<<(ostream &out,HoaDon x)
    {
        cout<<x.ma<<" "<<posKH[x.makh].ten<<" "<<posKH[x.makh].dc<<" "<<posMH[x.mamh].ten<<" "<<x.sl<<" "<<x.sl*posMH[x.mamh].giaban<<" "<<x.loinhuan<<"\n";
        return out;
    }
    friend bool operator<(const HoaDon a,const HoaDon b)
    {
        return a.loinhuan >= b.loinhuan;
    }
};
void sapxep(HoaDon a[],int sz)
{
    sort(a,a+sz);
}

int main(){
    freopen("thu.inp","r",stdin);
    KhachHang dskh[25];
    MatHang dsmh[45];
    HoaDon dshd[105];
    int N,M,K,i;
    cin >> N;
    for(i=0;i<N;i++) cin >> dskh[i];
    cin >> M;
    for(i=0;i<M;i++) cin >> dsmh[i];
    cin >> K;
    for(i=0;i<K;i++) cin >> dshd[i];

    sapxep(dshd, K);

    for(i=0;i<K;i++) cout << dshd[i];
    return 0;
}