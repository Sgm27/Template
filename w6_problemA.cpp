#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 250
int a[maxn],x[maxn],n,k;
vector<vector<int>> res;
void Try(int i,int sum)
{
    for (int j=x[i-1]+1;j<=n;j++)
        if (sum+a[j]<=k)
        {
            x[i]=j;
            if (sum+a[j]==k) 
            {
                vector<int> tmp(x+1,x+1+i);
                res.push_back(tmp);
            }
            else Try(i+1,sum+a[j]);
        }
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        res.clear();
        cin>>n>>k;
        for (int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n);
        x[0]=0;
        Try(1,0);
        if (!res.size())
        {
            cout<<"-1\n";
            continue;
        }
        for (auto it : res)
        {
            cout<<"[";
            for (int i=0;i<it.size()-1;i++) cout<<a[it[i]]<<" ";
            cout<<a[it.back()]<<"] ";
        }
        cout<<"\n";
    }
}

