#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 
map<string,vector<int>> save;
int cnt = 0;
string convert(string s)
{
    string new_s = "";
    stringstream ss(s);
    string token;
    while (ss >> token) new_s += toupper(token[0]);
    return new_s;
}
class SinhVien{
    public :
    string mgv,ten,mh;
    vector<string> name;
    SinhVien()
    {
        mgv = ten = mh = "";
        name.clear();
    }
    friend istream &operator>>(istream &in,SinhVien &x)
    {
        cnt++;
        string t = to_string(cnt);
        x.mgv = "GV" + string(2 - t.size(),'0') + t;
        getline(cin,x.ten);
        getline(cin,x.mh);
        stringstream SS(x.mh);
        string new_mh = "";
        while (SS >> t) new_mh += toupper(t[0]);
        x.mh = new_mh;
        save[x.mh].push_back(cnt);
        string token;
        stringstream ss(x.ten);
        while (ss >> token) 
        {
            FOR(i,0,token.size() - 1) token[i] = tolower(token[i]);
            x.name.push_back(token);
        }
        return in;
    }
    friend ostream &operator<<(ostream &out,SinhVien x)
    {
        cout<<x.mgv<<" "<<x.ten<<" "<<x.mh<<"\n";
        return out;
    }
    friend bool operator<(const SinhVien a,const SinhVien b)
    {
        if (a.name.back() != b.name.back()) 
            return a.name.back() < b.name.back();
        return a.mgv < b.mgv;
    }
};
bool ch(string s,string t)
{
    if (s.length() < t.length()) return false;
    FOR(i,0,s.length() - t.length())
        if (s.substr(i,t.length()) == t) return true;
    return false;
}
bool check(SinhVien a,string s)
{
    for (string t : a.name)
        if (ch(t,s)) return true;
    return false;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    SinhVien a[1005];
    int n; cin>>n;
    cin.ignore();
    FOR(i,1,n) cin>>a[i];
    int q; cin>>q;
    cin.ignore();
    while (q--)
    {
        string s; cin>>s;
        cout<<"DANH SACH GIANG VIEN THEO TU KHOA "<<s<<":\n";
        FOR(i,0,s.length() - 1) s[i] = tolower(s[i]);
        FOR(i,1,n)
            if (check(a[i],s)) cout<<a[i];
    }
}
