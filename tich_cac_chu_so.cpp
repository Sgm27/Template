#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int n;
void process()
{
    if (n==0)
    {
        cout<<"10";
        return;
    }
    if (n==1) 
    {
        cout<<n;
        return;
    }
    vector<int> v;
    int i=2,tmp=n;
    while (tmp!=1)
    {
        while (tmp%i==0) tmp/=i;
        i++;
        if (i>=10)
        {
            cout<<"-1";
            return;
        }
    }
    i=9;
    while (n!=1)
    {
        while (n%i==0)
        {
            v.push_back(i);
            n/=i;
        }
        i--;
    }
    reverse(v.begin(),v.end());
    for (int k : v) cout<<k;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    process();
}

