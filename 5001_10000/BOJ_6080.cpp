// Bad Grass - 실버 2

#include <bits/stdc++.h>

using namespace std;

int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0}, dy[8] = {1, 0, -1, 1, 0, -1, 1, -1};

typedef pair<int, int> pi;

int main() {
    int r, c; cin >> r >> c;

    vector<vector<int>> v(r, vector<int> (c, 0));
    vector<vector<bool>> visited(r, vector<bool> (c, false));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> v[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (visited[i][j] || !v[i][j]) continue;
            queue<pi> q;
            q.push({i, j});
            visited[i][j] = true;
            while (!q.empty()) {
                int x = q.front().first, y = q.front().second;
                q.pop();

                for (int i = 0; i < 8; i++) {
                    int nx = x + dx[i], ny = y + dy[i];

                    if (nx < 0 || nx >= r || ny < 0 || ny >= c || visited[nx][ny] || !v[nx][ny])continue;
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            cnt++;
        }
    }
    cout << cnt;

}