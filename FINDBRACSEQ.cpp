#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 
string s;
stack<char> st; 
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string tmp; cin>>tmp;
    for (char x : tmp)
        if (x==')' || x=='(') s+=x;
    int ans=0;
    for (char x : s)
    {
        if (x=='(') st.push(x);
        else 
        {
            if (st.empty()) continue;
            ans++;
            st.pop(); 
        }
    }
    cout<<ans*2;
}

