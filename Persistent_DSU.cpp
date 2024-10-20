struct PersistentDataStructure{
    vector<int> lab, time;

    PersistentDataStructure(int _) : lab(_ + 1), time(_ + 1) {
        for(int i = 1; i <= _; ++i)
            lab[i] = -1, time[i] = INT_MAX;
    }

    int root(int u, int ver){
        if(time[u] > ver) return u;
        return root(lab[u], ver);
    }

    void merge_set(int u, int v, int ver){
        u = root(u, ver);
        v = root(v, ver);
        if(u != v){
            if(lab[u] > lab[v]) swap(u, v);
            lab[u] += lab[v];
            lab[v] = u;
            time[v] = ver;
        }
    }

    char ask(int u, int v, int ver){
        return root(u, ver) == root(v, ver) ? 'Y' : 'N';
    }
};