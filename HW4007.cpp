#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int d[256];
void process(string s)
{
    memset(d,0,sizeof(d));
    int cnt=1;
    s[s.length()]='#';
    for (int i=0;i<s.length();i++)
    {
        if (s[i]==s[i+1]) cnt++;
        else 
        {
            if (cnt>1) cout<<s[i]<<cnt;
            else cout<<s[i];
            cnt=1;
        }
    }
    cout<<"\n";
}
int main()
{
//    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        string s;
        cin>>s;
        process(s);	
    }
}

