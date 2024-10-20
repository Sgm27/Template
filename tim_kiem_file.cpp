#include<iostream>
using namespace std;
using ll = long long;
#define maxn 
int n;
string s;
void process()
{
    int pos;
    for (int i=0;i<=s.length()-1;i++) 
        if (s[i]=='*') 
        {
            pos=i;
            break;           
        }
    string st1=s.substr(0,pos);
    string st2=s.substr(pos+1,s.length()-pos-1);
    for (int i=1;i<=n;i++)
    {
        string tmp;
        cin>>tmp;
        if (tmp.length()<s.length()-1) 
        {
            cout<<"NE\n";
            continue;
        }
        if (tmp.substr(0,st1.length())!=st1 || tmp.substr(tmp.length()-st2.length(),st2.length())!=st2)
        {
            cout<<"NE\n";
            continue;
        }
        cout<<"DA\n";
    }
}
int main()
{
    // freopen("thu.inp","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    cin>>s;
    process();
}

