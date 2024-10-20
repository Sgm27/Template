#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
// #define int long long
#define pii pair<int,int>
// const int MOD=1e9+7,INF=4e18;
#define maxn 
int cnt;
class SinhVien {
    public :
    string masv,ten,lop,ns;
    float gpa;
    SinhVien()
    {
        masv = ten = lop = ns = "";
        gpa = 0;
    }
    friend istream &operator>>(istream &in,SinhVien &x)
    {
        cin.ignore();
        getline(cin,x.ten);
        cin>>x.lop>>x.ns>>x.gpa;
        return in;
    }
    friend ostream &operator<<(ostream &out,SinhVien x)
    {
        cnt++;
        x.masv = "B20DCCN" + string(cnt < 10 ? 2 : 1,'0') + to_string(cnt);
        if (x.ns[1] == '/') x.ns = "0" + x.ns;
        if (x.ns[4] == '/') x.ns.insert(x.ns.begin() + 3,'0');
        cout<<x.masv<<" "<<x.ten<<" "<<x.lop<<" "<<x.ns<<" ";
        printf("%.2f",x.gpa); cout<<"\n";
        return out;
    }
};
int main(){
    SinhVien ds[50];
    int N, i;
    cin >> N;
    for(i=0;i<N;i++){
        cin >> ds[i];
    }
    for(i=0;i<N;i++){
        cout << ds[i];
    }
    return 0;
}