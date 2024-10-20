#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    cin.ignore();
    while (tc--)
    {
        string s;
        char x;	
        getline(cin,s);
        cin>>x;
        cin.ignore();
        for (char k : s)
            if (k!=x) cout<<k;
        cout<<endl;
    }
}

