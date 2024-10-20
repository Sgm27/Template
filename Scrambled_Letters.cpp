#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
string s[50005],Max[50005],Min[50005],tmp[50005];
int res1[50005],res2[50005];
void input()
{
    cin>>n;
    for (int i=1;i<=n;i++) 
    {
        cin>>s[i];
        string tmp=s[i];
        sort(tmp.begin(),tmp.end());
        Max[i]=tmp;
        reverse(tmp.begin(),tmp.end());
        Min[i]=tmp;
    }
}
void process()
{
    for (int i=1;i<=n;i++) tmp[i]=Min[i];
    sort(Min+1,Min+1+n);
    for (int i=1;i<=n;i++)
    {
        int it=lower_bound(Min+1,Min+1+n,Max[i])-Min;
        res1[i]=it;
    }
    for (int i=1;i<=n;i++) Min[i]=tmp[i];
    sort(Max+1,Max+1+n);
    // for (int i=1;i<=n;i++) cout<<Max[i]<<" "<<Min[i]<<endl;
    for (int i=1;i<=n;i++)
    {
        int it=upper_bound(Max+1,Max+1+n,Min[i])-Max-1;
        res2[i]=it;
    }
    for (int i=1;i<=n;i++) cout<<res1[i]<<" "<<res2[i]<<endl;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
}

