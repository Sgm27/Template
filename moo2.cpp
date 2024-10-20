#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n,m,max_len,len1=0,len2=0,res=0;
struct mang{
    int gt;
    int type=0;
};
mang a[1000005],b[1000005];
void input()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        int x; char s;
        cin>>x>>s;
        if (s=='L') a[len1+1].type=1;
        else a[len1+1].type=-1;
        len1+=x;
    }
    for (int i=1;i<=m;i++)
    {
        int x; char s;
        cin>>x>>s;
        if (s=='L') b[len2+1].type=1;
        else b[len2+1].type=-1;
        len2+=x;
    }
    max_len=max(len1,len2);
}
void process()
{
    a[0].gt=0;
    b[0].gt=0;
    int i=1,type;
    while (i<=len1)
    {
        if (a[i].type) type=a[i].type;
        if (type>0) a[i].gt=a[i-1].gt+1;
        else a[i].gt=a[i-1].gt-1;
        i++;
    }
    i=1;
    while (i<=len2)
    {
        if (b[i].type) type=b[i].type;
        if (type>0) b[i].gt=b[i-1].gt+1;
        else b[i].gt=b[i-1].gt-1;
        i++;
    }
    for (int i=len1+1;i<=max_len;i++) a[i].gt=a[len1].gt;
    for (int i=len2+1;i<=max_len;i++) b[i].gt=b[len2].gt;
    for (int i=1;i<=max_len;i++) 
        if (a[i].gt==b[i].gt && a[i-1].gt!=b[i-1].gt) res++;
    cout<<res;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
}

