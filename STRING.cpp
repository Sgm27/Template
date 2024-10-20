#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
int cnt[256],ans[256]; 
string s;
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>s;
    for (char x : s) cnt[x]++;
    for (int i='a';i<='z';i++) ans[i]=cnt[i]/2;
    string res;
    for (int i='a';i<='z';i++)
        while (ans[i])
        {
            res+=i;
            ans[i]--;
        }
    cout<<res;
}

