#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(string s)
{
    int l=0,r=s.length()-1;
    while (l<r)
    {
        if (s[l]!=s[r]) return false;
        l++;
        r--;
    }
    return true;
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        string s;
        cin>>s;
        int l=0,r=s.length();
        if (check(s)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}

