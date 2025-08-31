#include <bits/stdc++.h>
using namespace std;

int knight_moves(int N, int M, int Ki, int Kj, int Qi, int Qj) {
    vector<vector<int>> dist(N, vector<int>(M, -1));
    int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
    queue<pair<int, int>> q;
    q.push(make_pair(Ki, Kj));
    dist[Ki][Kj] = 0;
    while (!q.empty()) {
        pair<int, int> curr = q.front(); q.pop();
        int x = curr.first, y = curr.second;
        if (x == Qi && y == Qj) return dist[x][y];
        for (int d = 0; d < 8; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        int Ki, Kj, Qi, Qj;
        cin >> Ki >> Kj >> Qi >> Qj;
        cout << knight_moves(N, M, Ki, Kj, Qi, Qj) << endl;
    }
    return 0;
}