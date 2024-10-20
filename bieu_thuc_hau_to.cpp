#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string s;
int pre(char x)
{
    if (x=='(') return 0;
    if (x=='+' || x=='-') return 1;
    if (x=='*' || x=='/') return 2;
    return 3;
}
void process()
{
    stack<char> st;
    string res="";
    for (char x : s)
        if (isalpha(x)) res+=x;
        else
        {
            if (x=='(') st.push(x);
            else
            if (x==')')
            {
                while (!st.empty() && st.top()!='(') 
                {
                    res+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else 
            {
                while (!st.empty() && pre(st.top())>=pre(x))
                {
                    res+=st.top();
                    st.pop();
                }
                st.push(x);
            }
        }
    while (!st.empty()) 
    {
        res+=st.top();
        st.pop();
    }
    cout<<res<<endl;
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

