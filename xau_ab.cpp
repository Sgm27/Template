#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 
string s1,s2;
void process()
{
    int l=0,r=s2.length()-1,ptr=0;
    if (r-l+1<=s1.length())
    {
        cout<<"No";
        return;
    }
    while (r-l+1>s1.length())
    {
        if (!ptr)
        {
            if (s2[l]=='A') l++;
            else 
            {
                l++;
                ptr=1;
            }
        }
        else
        {
            if (s2[r]=='A') r--;
            else
            {
                r--;
                ptr=0;   
            }
        }
    }
    string tmp="";
    if (!ptr)  
        for (int i=l;i<=r;i++) tmp+=s2[i];
    else
        for (int i=r;i>=l;i--) tmp+=s2[i];
    if (tmp==s1) cout<<"Yes";
    else cout<<"No";
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>s1>>s2;
    process();
}

