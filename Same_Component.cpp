#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<string> grid;
vector<vector<bool>> visited;

bool bfs(int si, int sj, int di, int dj) {
    queue<pair<int, int>> q;
    q.push(make_pair(si, sj));
    visited[si][sj] = true;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    while (!q.empty()) {
        pair<int, int> curr = q.front(); q.pop();
        int x = curr.first, y = curr.second;
        if (x == di && y == dj) return true;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M &&
                !visited[nx][ny] && grid[nx][ny] == '.') {
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
    return false;
}

int main() {
    cin >> N >> M;
    grid.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }
    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    visited.assign(N, vector<bool>(M, false));
    if (grid[si][sj] != '.' || grid[di][dj] != '.') {
        cout << "NO" << endl;
        return 0;
    }
    cout << (bfs(si, sj, di, dj) ? "YES" : "NO") << endl;
    return 0;
}