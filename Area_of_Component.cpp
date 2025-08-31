#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<string> grid;
vector<vector<bool>> visited;

bool isvalid(int nx, int ny) {
    return nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] == '.' && !visited[nx][ny];
}

int bfs(int si, int sj) {
    int area = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(si, sj));
    visited[si][sj] = true;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    while (!q.empty()) {
        pair<int, int> par = q.front(); q.pop();
        int x = par.first, y = par.second;
        area++;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (isvalid(nx, ny)) {
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
    return area;
}

int main() {
    cin >> N >> M;
    grid.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }
    visited.assign(N, vector<bool>(M, false));
    int min_area = INT_MAX;
    bool found = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                int area = bfs(i, j);
                min_area = min(min_area, area);
                found = true;
            }
        }
    }
    if (found) cout << min_area << endl;
    else cout << -1 << endl;
    return 0;
}