#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define pii pair<int,int>
const int MOD=1e9+7,INF=9e18;
#define maxn 250005
int n,answer;
string s;
struct Node{
    Node *child[26];
    int count,exist;
    Node()
    {
        memset(child,0,sizeof(child));
        count = exist = 0;
    }
};
Node *root=new Node();
void Add(string s)
{
    Node *p=root;
    int Num=0; 
    // Num is number of string have added in the path from root -> s.end()
    for (char c : s)
    {
        int id = c-'a';
        if (p->child[id] == NULL) p->child[id] = new Node();
        p = p->child[id];
        p->count++;
        if (p->exist) Num++; 
    }
    p->exist = 1;
    answer = max(answer,Num + 1);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    while (n--)
    {
        cin>>s;
        Add(s);
    }
    cout<<answer;
}
