#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 105
int n,p[maxn];
void process()
{
    for (int i=1;i<=n;i++)
    {
        int tmp1=i;
        int tmp2=p[i];
        int tmp3=p[tmp2];
        int tmp4=p[tmp3];
        if (tmp1==tmp4) 
        {
            cout<<"<3\n";
            return;
        }
    }
    cout<<"</3\n";
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        cin>>n;
        for (int i=1;i<=n;i++) cin>>p[i];
        process();
    }
}

