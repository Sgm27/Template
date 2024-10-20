#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 
string s;
void process()
{
    string tmp1=s.substr(0,s.length()/2);
    string tmp2=s.substr(s.length()/2,s.length()/2);
    int num_change1=0,num_change2=0;
    for (char x : tmp1) num_change1+=x;
    for (char x : tmp2) num_change2+=x;
    for (int i=0;i<tmp1.length();i++)
    {
        int t=tmp1[i]+num_change1;
        while (t>90) t-=26;
        tmp1[i]=(char)(t);
    }
    for (int i=0;i<tmp2.length();i++)
    {
        int t=tmp2[i]+num_change2;
        while (t>90) t-=26;
        tmp2[i]=(char)(t);
    }
    for (int i=0;i<tmp1.length();i++)
    {
        int num_change=tmp2[i]-65;
        int t=tmp1[i]+num_change;
        while (t>90) t-=26;
        tmp1[i]=(char)t;
    }
    cout<<tmp1<<"\n";
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>s;
        process();	
    }
}

