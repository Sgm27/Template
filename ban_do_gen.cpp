#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
int n,k;
const int MOD=1e9+7;
vector<pair<char,char>> v;
int calc(string s)
{
    int sum1=1,sum2=1,n=s.length()-1;
    for (int i=1;i<=n/2;i++) 
        if (s[i]==s[0]) sum1++;
    for (int i=n-1;i>=n/2;i--)
        if (s[i]==s[n]) sum2++;
    return min(sum1,sum2);
} 
void input()
{
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        string s;
        pair<char,char> tmp;
        cin>>s;
        if (calc(s)>=k) v.push_back({s[0],s[s.length()-1]});
    }
}
bool cmp(pair<char,char> x,pair<char,char> y)
{
    if (x.first!=y.first) return x.first<y.first;
    return x.second<y.second;
}
void process()
{
    sort(v.begin(),v.end(),cmp);
    v.push_back({'.','.'});
    v.insert(v.begin(),{'.','.'});
    int idx=1;
    ll res=0;
    while (idx<=v.size()-2)
    {
        if (v[idx]==v[idx+1])
        {
            int cnt=1;
            while (v[idx]==v[idx+1]) 
            {
                cnt++;
                idx++;
            }
            res+=cnt-1;
            res%=MOD;
        }
        else idx++;
    }
    cout<<res;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    input();
    process();
}

