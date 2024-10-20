#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string s1,s2;
int d[1000005];
void input()
{
    cin>>s1>>s2;
    for (int i=0;i<=s2.length();i++) d[i]=1;
}
void process()
{
    int cnt=0;
    for (int i=0;i<s1.length();i++)
        for (int j=0;j<s2.length();j++)
            if (d[j] && s1[i]==s2[j]) 
            {
                cnt++;
                d[j]=0;
            }
    cout<<s1.length()+s2.length()-2*cnt;
}
int main()
{
   // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
}

