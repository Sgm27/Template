#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string s;
void input()
{
    cin>>s;
}
void process()
{
    if (s.length()%2)
    {
        for (int i=1;i<=s.length()/2+1;i++) cout<<"4";
        for (int i=s.length()/2+2;i<=s.length()+1;i++) cout<<"7";
        return;
    }
    int n=s.length();
    if (s[0]>'7') 
    {
        n++;
        if (n%2) n++;
        for (int i=1;i<=n/2;i++) cout<<"4";
        for (int i=n/2+1;i<=n;i++) cout<<"7";
        return;
    }
    bool check=false;
    int sl4=0,sl7=0;
    for (int i=0;i<s.length();i++)
    {
        if (check)
        {
            while (sl4<=n/2) cout<<"4";
            while (sl7<=n/2) cout<<"7";
            return;
        }
        if (s[i]<'4') 
        {
            cout<<"4";
            sl4++;
            check=true;
        }
        else
        if (s[i]=='4') 
        {
            cout<<"4";
            sl4++;
        }
        if (s[i])

    }
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
}

