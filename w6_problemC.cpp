#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 
vector<vector<int>> res;
int x[20],sum;
void Try(int i)
{
    for (int j=x[i-1];j>=1;j--)
        if (sum-j>=0)
    {
        x[i]=j;
        sum-=x[i];
        if (!sum) 
        {
            vector<int> tmp(x+1,x+i+1);
            res.push_back(tmp);
        }
        else Try(i+1);
        sum+=x[i];
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
        int n;
        cin>>n;
        x[0]=n;
        sum=n;
        Try(1);
        for (auto it : res)
        {
            cout<<"(";
            for (int i=0;i<it.size()-1;i++) cout<<it[i]<<" ";
            cout<<it.back()<<") ";
        }
        cout<<"\n";
    }
}

