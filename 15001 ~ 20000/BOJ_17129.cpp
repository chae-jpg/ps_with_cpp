#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int main() {
    int n, m, cnt = -1, ans = -1;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int> (m, 0));
    vector<vector<bool>> visited(n, vector<bool> (m, false));
    pi start;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            int k; k = c-'0'; v[i][j] = k;
            if (v[i][j] == 2) start = {i, j};
        }
    }

    queue<pi> q;
    visited[start.first][start.second] = true;
    q.push(start);

    while (!q.empty()) {
        bool end = false;
        int len = q.size();
        cnt++;
        for (int j = 0; j < len; j++) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            if (v[x][y] != 0 && v[x][y] != 2) {
                ans = v[x][y];
                end = true;
                break;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || v[nx][ny] == 1 || visited[nx][ny]) continue;
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
        if (end) break;
    }
    if (ans != -1) {
        cout << "TAK\n" << cnt;
    } else {
        cout << "NIE";
    }



}