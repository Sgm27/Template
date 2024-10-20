#ifdef DS
    #include "debug.h"
#else 
    #include<bits/stdc++.h>
    #define deb(...) 
#endif
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define NALL(x) x.begin()+1,x.end()
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define vi vector<int>
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 

struct SegTree {
    struct Node {
        int ll, rr;
        int ans;
        Node *left, *right;
        Node(int l, int r) {
            ll = l;
            rr = r;
            ans = -INF;
            left = NULL;
            right = NULL;
        }
    };
    Node *roott = new Node(1, 1e9);
    void upd(Node *root, int pos, int val) {
        if (pos < root->ll || pos > root->rr) {
            return;
        }
        if (pos == root->ll && pos == root->rr) {
            root->ans = val;
            return;
        }
        int mid = (root->ll + root->rr) >> 1;
        if (root->left == NULL) {
            root->left = new Node(root->ll, mid);
        }
        if (root->right == NULL) {
            root->right = new Node(mid + 1, root->rr);
        }
        upd(root->left, pos, val);
        upd(root->right, pos, val);
        root->ans = max(root->left->ans, root->right->ans);
        return;
    }
    Node get(Node *root, int l, int r) {
        if (root->rr < l || root->ll > r || root == NULL) {
            return Node(0, 0);
        }
        if (root->ll >= l && root->rr <= r) {
            return *root;
        }
        Node gl = Node(0, 0);
        Node gr = Node(0, 0);
        if (root->left != NULL) {
            gl = get(root->left, l, r);
        }

        if (root->right != NULL) {
            gr = get(root->right, l, r);
        }
        Node g = Node(0, 0);
        g.ans = max(gl.ans, gr.ans);
        return g;
    }
};

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n; cin>>n;
    vi a(n+1);
    FOR(i,1,n) cin>>a[i];
    SegTree st;
    FOR(i,1,n)
        st.upd(st.roott, i, a[i]);
    int q; cin>>q;
    while (q--)
    {
        int type; cin>>type;
        if (type == 1)
        {
            int pos, val; cin>>pos>>val;
            st.upd(st.roott, pos, val);
        }
        else 
        {
            int l,r; cin>>l>>r;
            cout<<st.get(st.roott, l, r).ans<<"\n";
        }
    }
}
