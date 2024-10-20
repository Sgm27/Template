#include<bits/stdc++.h>
using namespace std;
int k;
void input()
{
    cin>>k;
}
void process()
{
    if (k<=3) 
    {
        if (k==1) cout<<"m";
        else cout<<"o";
        return;
    }
    int sum=3,cs=3,pre_sum;
    while (sum<k) sum=2*sum+(++cs);
    while (cs>3)
    {
        pre_sum=(sum-cs)/2;
        if (k>pre_sum && k<=pre_sum+cs) 
        {
            if (k-pre_sum==1) cout<<"m";
            else cout<<"o";
            return;
        }
        else
        {
            if (k>pre_sum+cs)
            {
                k=k-pre_sum-cs;
            }
            cs--;
            sum=pre_sum;
        }
    }
    if (k==1) cout<<"m";
    else cout<<"o";
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    input();
    process();
}

