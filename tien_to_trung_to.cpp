#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string s;
void process()
{
    stack<string> st;
    for (int i=s.length()-1;i>=0;i--)
    {
        if (isalpha(s[i])) st.push(string(1,s[i]));
        else
        {
            string op1=st.top(); st.pop();
            string op2=st.top(); st.pop();
            string tmp="("+op1+s[i]+op2+")";
            st.push(tmp);
        }
    }
    cout<<st.top()<<"\n";
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>s;
        process();	
    }
}

