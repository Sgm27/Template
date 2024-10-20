#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int d[256];
void process(string s)
{
    int check=0;
    memset(d,0,sizeof(d));
    for (char x : s) d[x]++;
    for (char x : s)
        if (d[x]>1) 
        {
            check=1;
            cout<<(char)x<<" "<<d[x]<<"\n";
            d[x]=0;
        }
    if (!check) cout<<"-1\n";
}
int main()
{
    // freopen("thu.inp","r",stdin);
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

