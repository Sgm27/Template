#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
int n,d[100005];
char b[100005];
struct mang{
    char gt;
    int cs;
};
mang a[100005];
void input()
{
    for (int i=1;i<=n;i++) d[i]=0;
    cin>>n;
    for (int i=1;i<=n;i++) 
    {
        cin>>a[i].gt;
        b[i]=a[i].gt;
        a[i].cs=i;
    }
}
bool cmp(mang a,mang b)
{
    if (a.gt!=b.gt) return a.gt<b.gt;
    else return a.cs>b.cs;
}
void process()
{
    string resA="",resB="";
    sort(a+1,a+1+n,cmp);
    int l=1,r=n,check=0;
    while (!check)
    {
        while (d[r]==1) 
        {
            r--;
            if (r<1) check=1;
        }
        if (check) continue;
        resA+=b[r];
        d[r]=1;
        while (d[a[l].cs]==1) 
        {
            l++;
            if (l>n) check=1;
        }
        if (check) continue;
        resB+=a[l].gt;
        d[a[l].cs]=1;
    }
    if (resA<=resB) 
    {
        cout<<"NE\n";
        cout<<resB;
    }
    else{
        cout<<"DA\n";
        cout<<resB;
    }
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
}

