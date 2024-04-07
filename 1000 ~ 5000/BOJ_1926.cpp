//그림 - 실버 1

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

vector<vector<bool>> visited;

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> board(n, vector<int> (m, false));
    visited.assign(n, vector<bool> (m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    queue<pi> q;
    int ans = -1, drawing = 0;
    for (int i= 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] || !board[i][j]) continue;
            drawing++;
            q.push({i, j});
            int cnt = 1;
            while(!q.empty()) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                visited[x][y] = true;
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || !board[nx][ny]) continue;
                    cnt++;
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            ans = max(ans, cnt);
        }
    }
    cout << drawing << '\n';
    if (ans == -1) cout << 0;
    else cout << ans;
}