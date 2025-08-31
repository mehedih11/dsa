#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<string> maze;
vector<vector<bool>> visited;
vector<vector<pair<int, int>>> parent;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool bfs(int sx, int sy, int& ex, int& ey) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny]) {
                if (maze[nx][ny] == 'D') {
                    parent[nx][ny] = {x, y};
                    ex = nx; ey = ny;
                    return true;
                }
                if (maze[nx][ny] == '.') {
                    visited[nx][ny] = true;
                    parent[nx][ny] = {x, y};
                    q.push({nx, ny});
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> N >> M;
    maze.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> maze[i];
    }
    visited.assign(N, vector<bool>(M, false));
    parent.assign(N, vector<pair<int, int>>(M, {-1, -1}));

    int sx = -1, sy = -1, ex = -1, ey = -1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (maze[i][j] == 'R') {
                sx = i; sy = j;
            }

    if (bfs(sx, sy, ex, ey)) {
        int x = ex, y = ey;
        while (parent[x][y].first != -1) {
            auto [px, py] = parent[x][y];
            if (maze[px][py] == '.') maze[px][py] = 'X';
            x = px; y = py;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << maze[i] << endl;
    }
    return 0;
}