#include<bits/stdc++.h>
using namespace std;
using ll = long long;
map<char,int> mp;
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        mp.clear();
        int cs=9;
        string s;
        cin>>s;
        for (char x : s) 
        {
            if (!mp.count(x)) 
            {
                mp[x]=cs;
                cs--;
            }
        }
        if (mp.size()>10) cout<<"-1";
        else 
            for (char x : s) cout<<mp[x];
        cout<<endl;
    }
}

