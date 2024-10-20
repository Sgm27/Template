#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100005
int n,a[maxn];
priority_queue<int,vector<int>,greater<int>> Q;
// priority_queue<int> Q;
int main()
{
    freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n; 
    for (int i=1;i<=n;i++) 
    {
        cin>>a[i];
        Q.push(a[i]);
    }
    while (!Q.empty()) 
    {
        cout<<"---";
        cout<<Q.top()<<"\n";
        Q.pop();
    }
}

