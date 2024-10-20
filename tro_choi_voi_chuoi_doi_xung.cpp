#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int d[256];
string s;
void process(string s)
{
    memset(d,0,sizeof(d));
    int cnt=0;
    for (char k : s)
        d[k]++;
    while (1)
    {
        cnt++;
        int tmp=0;
        for (int i=97;i<=122;i++) 
            if (d[i]%2) tmp++;
        if (tmp<=1) break;
        for (int i=97;i<=122;i++)
            if (d[i]%2) 
            {
                d[i]--;
                continue;ư
            }
    }
    if (cnt%2) cout<<"First\n";
    else cout<<"Second\n";
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    while (cin>>s)
    {
        process(s);
    }
}

