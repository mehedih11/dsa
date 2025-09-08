#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main() {
    int N, E;
    cin >> N >> E;
    vector<tuple<int, int, ll>> edges;
    for (int i = 0; i < E; i++) {
        int A, B;
        ll W;
        cin >> A >> B >> W;
        edges.push_back({A, B, W});
    }
    int S;
    cin >> S;
    int T;
    cin >> T;
    vector<int> queries(T);
    for (int i = 0; i < T; i++) {
        cin >> queries[i];
    }

    vector<ll> dist(N + 1, INF);
    dist[S] = 0;
    bool negative_cycle = false;
    for (int i = 1; i <= N; i++) {
        bool updated = false;
        for (auto& e : edges) {
            int u, v;
            ll w;
            tie(u, v, w) = e;
            if (dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                updated = true;
            }
        }
        if (i == N && updated) {
            negative_cycle = true;
            break;
        }
    }

    if (negative_cycle) {
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }

    for (int i = 0; i < T; i++) {
        int D = queries[i];
        if (dist[D] == INF) cout << "Not Possible" << endl;
        else cout << dist[D] << endl;
    }
    return 0;
}