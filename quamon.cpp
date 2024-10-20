#include <bits/stdc++.h>
using namespace std;
int n,m,a[100001];
long long s[100001];
struct tmp{
    int x,y;
};
tmp b[100001];
void nhap()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++)
    {
        cin>>b[i].x>>b[i].y;
    }
}
int binarys(tmp a[],int d,int c,int key)
{
    int ans=-1;
    while (d<=c)
    {
        int mid=(d+c)/2;
        if (a[mid].x<=key)
        {
            ans=mid;
            d=mid+1;
        }
        else c=mid-1;
    }
    return ans;
}
bool cmp(tmp a,tmp b)
{
    return a.x<b.x;
}
void xuly()
{
    sort(b+1,b+1+m,cmp);
    s[0]=0;
    for (int i=1;i<=m;i++) s[i]=s[i-1]+b[i].y;
   // for (int i=1;i<=m;i++) cout<<b[i].x<<" "<<b[i].y<<endl;
    for (int i=1;i<=n;i++)
    {
        int k=binarys(b,1,m,a[i]);
        if (k!=-1) cout<<s[k]<<" ";
    }
}
int main()
{
    //freopen("thu.inp","r",stdin);
    nhap();
    xuly();
}
