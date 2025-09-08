#include <bits/stdc++.h>
using namespace std;
long long ll = LONG_LONG_MAX;

class Age {
public:
    int A, B;
    long long W;
    Age(int a, int b, long long w) : A(a), B(b), W(w) {}
};

int main() {
    int N, E;
    cin >> N >> E;
    vector<Age> edges;
    for (int i = 0; i < E; i++) {
        int A, B;
        long long W;
        cin >> A >> B >> W;
        edges.push_back(Age(A, B, W));
    }
    int S;
    cin >> S;
    int T;
    cin >> T;
    vector<int> queries(T);
    for (int i = 0; i < T; i++) {
        cin >> queries[i];
    }

    vector<long long> dist(N + 1, ll);
    dist[S] = 0;
    bool negative_cycle = false;
    for (int i = 1; i <= N; i++) {
        bool updated = false;
        for (auto& e : edges) {
            int u = e.A, v = e.B;
            long long w = e.W;
            if (dist[u] != ll && dist[v] > dist[u] + w) {
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
        if (dist[D] == ll) cout << "Not Possible" << endl;
        else cout << dist[D] << endl;
    }
    return 0;
}