#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define pii pair<int,int>
const int MOD=1e9+7,INF=1e9;
#define maxn 
int n;
struct Node{
    Node *child[26];
    int exist;
    Node()
    {
        memset(child,0,sizeof(child));
        exist = 0;
    }
};
Node *root = new Node();
void add(string s)
{
    Node *p = root;
    for (int c : s)
    {
        int id = c - 'a';
        if (p->child[id] == NULL) p->child[id] = new Node();
        p = p->child[id];
    }  
    p->exist++;
}
string answer = "",Max;
void dfs(Node *p,int cur,bool in)
{
    while (p->exist) answer += "P", p->exist--;
    if (cur == Max.size()) return;
    if (in)
    {
        int id = Max[cur] - 'a';
        FOR(i,0,25)
            if (i != id && p->child[i] != NULL)
            {
                answer += (i + 'a');
                dfs(p->child[i],-1,0);
                answer += "-";
            }
        answer += Max[cur];
        dfs(p->child[id],cur + 1,1);
    }
    else
    {
        FOR(i,0,25)
            if (p->child[i] != NULL)
            {
                answer += (i + 'a');
                dfs(p->child[i],-1,0);
                answer += "-";
            }
    }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,1,n)
    {
        string t; cin>>t;
        if (t.size() > Max.size()) Max = t;
        add(t);
    }
    dfs(root,0,1);
    cout<<answer.size()<<"\n";
    cout<<answer;
}
