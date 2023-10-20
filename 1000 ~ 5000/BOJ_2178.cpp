// 미로 탐색 - 실버 1

#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

vector<vector<int>> maze;
vector<vector<bool>> visited;

int bfs(int n, int m) {
    queue<pi> q;
    int x[4] = {-1, 1, 0, 0}, y[4] = {0, 0, -1, 1};
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        pi top = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int new_x = top.first + x[i], new_y = top.second + y[i];

            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && !visited[new_x][new_y] && maze[new_x][new_y]) {
                q.push({new_x, new_y});
                maze[new_x][new_y] = maze[top.first][top.second] + 1;
                visited[new_x][new_y] = true;
            }
        }
    }
    return maze[n-1][m-1];
}

int main() {
    int n, m;
    char t;
    cin >> n >> m;
    maze.assign(n, vector<int> (m, 0));
    visited.assign(n, vector<bool> (m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> t;
            maze[i][j] = t-'0';
        }
    }

    cout << bfs(n, m);


}