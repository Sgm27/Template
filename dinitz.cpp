
struct Dinitz {
    struct Edge { // u -> v
        int u, v, cost, cap, flow=0;
    };
 
    vector<Edge> edges;
    vector<vector<int>> g;
    vector<int> dist, ptr; // uses dist instead of level
 
    int n, src, sink;
    Dinitz(int nn, int s, int t){
        this->n = nn + 1; 
        src = s;
        sink = t;
        g.resize(n);
    }
 
    void addEdge(int u, int v, int cost, int cap, int rcap = 0) { // rcap = retrocapacity for bidiretional edges
        g[u].push_back( (int)edges.size() );
        edges.push_back({u, v, cost, cap});
        g[v].push_back( (int)edges.size() );
        edges.push_back({v, u, -cost, rcap});
    }
 
    bool find_augment_path() {
        dist.assign(n, INF);
        vector<bool> inqueue(n, false);
 
        queue<int> q; q.push(src);
        dist[src] = 0;
        inqueue[src] = true;
 
        while (!q.empty()) {
            int u = q.front(); q.pop();
            inqueue[u] = false;
 
            for (auto eid : g[u]) {
                auto const& e = edges[eid];
                if (e.flow >= e.cap) continue;
                if (dist[e.u] + e.cost < dist[e.v]) {
                    dist[e.v] = dist[e.u] + e.cost;
                    if (!inqueue[e.v]) {
                        q.push(e.v);
                        inqueue[e.v] = true;
                    }
                }
            }
        }
        return dist[sink] != INF;
    }
 
    int min_cost = 0;
    int dfs(int u, int f) {
        if (f == 0 or u == sink) return f;
        for (int &i = ptr[u]; i < (int)g[u].size();) {
            int eid = g[u][i++];
            auto &e = edges[eid];
            if(e.flow >= e.cap or (dist[e.u] + e.cost) != dist[e.v]) continue;
            int newf = dfs(e.v, min(f, e.cap - e.flow));
            if (newf == 0) continue;
            e.flow += newf;
            edges[eid^1].flow -= newf;
            min_cost += e.cost * newf;
            return newf;
        }
        return 0;
    }
 
    int max_flow = 0;
    pair<int, int> getFlow(bool reset_flow_cost = true) {
        if (reset_flow_cost) {
            max_flow = 0;
            min_cost = 0;
            for(int u=0; u<n; u++) {
                for(auto eid : g[u]) {
                    auto &e = edges[eid];
                    e.flow = 0;
                }
            }
        }
        while (find_augment_path()) {
            ptr.assign(n, 0);
            while (int newf = dfs(src, INF))
                max_flow += newf;
        }
        return {min_cost, max_flow};
    }
};