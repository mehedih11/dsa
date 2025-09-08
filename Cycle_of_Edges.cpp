#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }
    int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }
    bool unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;
        if (rank[pu] < rank[pv]) parent[pu] = pv;
        else if (rank[pu] > rank[pv]) parent[pv] = pu;
        else { parent[pv] = pu; rank[pu]++; }
        return true;
    }
};

int main() {
    int N, E;
    cin >> N >> E;
    DSU dsu(N);
    int cycle_edges = 0;
    for (int i = 0; i < E; i++) {
        int A, B;
        cin >> A >> B;
        if (!dsu.unite(A, B)) cycle_edges++;
    }
    cout << cycle_edges << endl;
    return 0;
}