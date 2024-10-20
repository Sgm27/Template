#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> uoc[1005],prime;
int n,x[1005];
ll res=1e18;
void input()
{
    cin>>n;
}
bool nto(int k)
{
    if (k==2 || k==3) return 1;
    if (k<2 || k%2==0 || k%3==0) return 0;
    int i=5;
    while (i<=sqrt(k))
    {
        if (k%i==0 || k%(i+2)==0) return 0;
        else i+=6;
    }
    return 1;
}
void sang()
{
    for (int i=1;i<=n;i++) uoc[i].push_back(i);
    for (int i=2;i<=sqrt(n);i++)
        for (int j=i*i;j<=n;j+=i)
        {
            uoc[j].push_back(i);
            if (i!=j/i) uoc[j].push_back(j/i);
        }
    for (int i=2;i<=n;i++)  
    {
        sort(uoc[i].begin(),uoc[i].end());
        if (uoc[i].size()==1) prime.push_back(i);
    }
}
void process(int n)
{
    int idx=0;
    ll tmp=1;
    for (int i=1;i<n;i++)
    {
        for (int k=1;k<=x[i]-1;k++)
        {
            if (tmp<=res/prime[idx]) tmp*=prime[idx];
            else return;
            if (tmp>res) return;
        }
        idx++;
    }
    res=min(res,tmp);
}
void Try(int i,int n)
{
    for (int k : uoc[n])
    {
        x[i]=k;
        if (n==1) process(i);
        else Try(i+1,n/k);
    }
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    sang();
    if (nto(n))
    {
        ll res=1;
        for (int i=1;i<n;i++) res*=2;
        cout<<res;
        return 0;
    }
    Try(1,n);
    cout<<res;
}

