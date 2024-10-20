#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 
string s;
int k;
void process()
{
    string t=s;
    sort(t.begin(),t.end(),greater<char>());
    int idx=-1;
    while (k)
    {
        idx++;
        if (t==s) break;
        char Max=s[idx];
        int cs=idx;
        for (int i=idx;i<=min(idx+k,(int)(s.length()-1));i++)
        {
            if (s[i]>Max)
            {
                Max=s[i];
                cs=i;
            }
        }
        for (int i=cs;i>idx;i--) swap(s[i],s[i-1]);
        k-=(cs-idx);
    }
    cout<<s;
}
int main()
{
     freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>s>>k;
    process();
}

