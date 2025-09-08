#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main() {
    int N, E;
    cin >> N >> E;
    vector<vector<ll>> dist(N + 1, vector<ll>(N + 1, INF));
    for (int i = 1; i <= N; i++) dist[i][i] = 0;
    for (int i = 0; i < E; i++) {
        int A, B;
        ll W;
        cin >> A >> B >> W;
        dist[A][B] = min(dist[A][B], W); // handle multiple edges
    }
    // Floyd-Warshall
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int X, Y;
        cin >> X >> Y;
        if (dist[X][Y] == INF) cout << -1 << endl;
        else cout << dist[X][Y] << endl;
    }
    return 0;
}