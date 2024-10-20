#include<iostream>
#include<stack>
using namespace std;
using ll = long long;
#define maxn 500005
int n,a[maxn];
void input()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
}
void process()
{
    stack<int> st;
    ll res=0;
    for (int i=1;i<=n;i++)
    {
        if (st.empty()) st.push(i);
        else
        {
            while (!st.empty() && a[i]>a[st.top()])
            {
                res+=i-st.top();
                st.pop();
            }
            st.push(i);
        }
    }
    cout<<res<<endl;
    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    res+=st.size()-1;
    // cout<<res;
}
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
}

