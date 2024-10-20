#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 
int n;
string s1,s2;
set<char> se;
void process()
{
    if (s1==s2)
    {
        cout<<"YES\n";
        return;
    }
    if (s2<s1)
    {
        cout<<"NO\n";
        return;
    }
    int d1[256]={},d2[256]={};
    for (char x : s1) d1[x]++;
    for (char x : s2) d2[x]++;
    if ((d1['a']!=d2['a']) || (d1['b']!=d2['b']) || (d1['c']!=d2['c']) )
    {
        cout<<"NO\n";
        return;
    }
    s1+="#";
    s2+="#";
    int idx=0;
    while (idx<s1.length())
    {
        if (s1[idx]==s2[idx]) idx++;
        else
        {
            int cnt1[256]={},cnt2[256]={};
            int st=idx;
            se.clear();
            while (se.size()<=2) 
            {
                cnt1[s1[idx]]++;
                cnt2[s2[idx]]++;
                se.insert(s1[idx]);
                se.insert(s2[idx]);
                idx++;
            }
            idx--;
            cnt1[s1[idx]]--;
            cnt2[s2[idx]]--;
            if ((cnt1['a']!=cnt2['a']) || (cnt1['b']!=cnt2['b']) || (cnt1['c']!=cnt2['c']) )
            {
                cout<<"NO\n";
                return;
            }
            if (s1[st]<s2[st] && se.count('b')) continue;
            else 
            {
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n;
        cin>>s1>>s2;
        process();
    }
}

