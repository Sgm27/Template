#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<time.h>
using namespace std;
using ll = long long;
#define maxn 
int n;
vector<string> res;
string s="";
string d[6]={"2","5","1","3","7","9"};
bool nto(ll k)
{
    if (k==2 || k==3) return true;
    if (k%2==0 || k%3==0 || k<2) return false;
    ll i=5;
    while (i<=sqrt(k))
    {
        if (k%i==0 || k%(i+2)==0) return false;
        else i+=6;
    }
    return true;
}
void Try(int i)
{
    int j;
    if (i==1) j=0; else j=2;
    for (j;j<=5;j++)  
        if (nto(stoll(s+d[j])))
        {
            s+=d[j];
            if (i==n) res.push_back(s);
            else Try(i+1);
            s.pop_back();
        }
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    Try(1);
    sort(res.begin(),res.end());
    for (string x : res) cout<<x<<" ";
}

