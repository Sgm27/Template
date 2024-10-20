#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int d1[256],d2[256];
void process(string s1,string s2)
{
    memset(d1,0,sizeof(d1));
    memset(d2,0,sizeof(d2));
    string res1="",res2="";
    int check=0;
    for (char x : s1) d1[x]=1;
    for (char x : s2) 
        if (!d1[x]) 
        {
            check=1;
            res1+=x;
            d1[x]=1;
        }
    for (char x : s2) d2[x]=1;
    for (char x : s1) 
        if (!d2[x]) 
        {
            check=1;
            res2+=x;
            d2[x]=1;
        }
    if (check) cout<<res2<<res1<<endl;
    else cout<<"-1\n";
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        string s1,s2;
        cin>>s1>>s2;
        process(s1,s2);	
    }
}

