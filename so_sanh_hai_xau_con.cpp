#include<bits/stdc++.h>
using namespace std;
#define maxn 500005
using ll = long long;
int sum[30][maxn];
string s;
void input()
{
    cin>>s;
}
void init()
{
    int n=s.length();
    s="#"+s;
    for (int i=1;i<=26;i++) sum[i][0]=0;
    for (int i=1;i<=n;i++) 
    {
        for (int k=1;k<=26;k++) sum[k][i]=sum[k][i-1];
        sum[s[i]-96][i]=sum[s[i]-96][i-1]+1;
    }
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    init();
    int q;
    cin>>q;
    while (q--)
    {
        int a,b,c,d,check=1;
        cin>>a>>b>>c>>d;
        for (int i=1;i<=26;i++)
            if (sum[i][b]-sum[i][a-1]!=sum[i][d]-sum[i][c-1])
            {
                cout<<"NO\n";
                check=0;
                break;
            }
        if (check) cout<<"YES\n";
    }
}

