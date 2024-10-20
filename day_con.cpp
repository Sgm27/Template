#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 100001
int a[maxn],n,ts[maxn],k;
set<int> se;
void input()
{
    ts[0]=0;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        ts[i]=ts[i-1];
        cin>>a[i];
        if (!se.count(a[i])) 
        {
            se.insert(a[i]);
            ts[i]++;
        }
    }
}
int Search(int l,int r,int a[],int key)
{
    int ans=-1;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (key>=a[mid])
        {
            
            l=mid+1;
        }
        else 
        {
            ans=mid;
            r=mid-1;
        }
    }
    return ans;
}
void process()
{
    int res=0;
    for (int i=0;i<=n;i++)
    {
        int tmp=Search(i,n,ts,ts[i]+k);
        if (tmp!=-1) res=max(res,tmp-i-1);
        //if (tmp==-1) return;
    }
    cout<<res;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    input();
    process();
}

