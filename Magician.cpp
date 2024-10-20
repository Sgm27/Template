#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
string id,hero,res;
bool lower(string a,string b)
{
    if (a.length()!=b.length())
        if (a.length()<=b.length()) return true;
        else return false;
    return a<b;
}
void process()
{
    string resulf="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    cin>>n;
    for (int i=1;i<=n;i++) 
    {
        cin>>id>>hero>>res;
        if (hero=="AM" && res=="W") 
            if (lower(id,resulf)) resulf=id; 
    }
    cout<<resulf;
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    process();
}

