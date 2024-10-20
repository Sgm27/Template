#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n,k,a[105][105];
void process()
{
    bool check1=false,check0=false;
    if (k>n)
    {
        cout<<"Draw"<<endl;
        return;
    } 
    // kiem tra theo hang
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n-k+1;j++)
        {
            int sum;
            if (!check0)
            {
                sum=0;
                for (int x=j;x<=j+k-1;x++) sum+=a[i][x];
                if (sum==0) 
                {
                    check0=true;
                    break;
                }
            }
            if (!check1)
            {
                sum=0;
                for (int x=j;x<=j+k-1;x++) sum+=a[i][x];
                if (sum==k) 
                {
                    check1=true;
                    break;
                }
            }
        }
    // kiem tra theo cot
    for (int i=1;i<=n-k+1;i++)
        for (int j=1;j<=n;j++)
        {
            int sum;
            if (!check0)
            {
                sum=0;
                for (int x=i;x<=i+k-1;x++) sum+=a[x][j];
                if (sum==0)
                {
                    check0=true;
                    break;
                }
            }
            if (!check1)
            {
                sum=0;
                for (int x=i;x<=i+k-1;x++) sum+=a[x][j];
                if (sum==k)
                {
                    check1=true;
                    break;
                }
            }
        }
    if ((check1 && check0) || (!check1 && !check0))
    {
        cout<<"Draw\n";
    }
    else
    if (check1 && !check0)
    {
        cout<<"Game de\n";
    }
    else cout<<"Chap thoi\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc;
    cin>>tc;
    while (tc--)
    {
        cin>>n>>k;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++) cin>>a[i][j];
        process();
    }
}

