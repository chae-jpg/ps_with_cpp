#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<char>> v (r, vector<char> (c, ' '));
        vector<vector<bool>> visited(r, vector<bool> (r, false));
        pi start;
        vector<pi> end;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> v[i][j];
                if (v[i][j] == 'S') start = {i, j};
                if (v[i][j] == 'G') end.push_back({i, j});
            }
        }

        queue<pi> q;
        q.push(start);
        visited[start.first][start.second] = true;
        bool is_end = false;

        int cnt = 0;
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                pi top = q.front();
                int x = top.first, y = top.second;
                q.pop();
                for (pi goal : end) {
                    if (goal == make_pair(x, y)) {
                        is_end = true;
                        break;
                    }
                }
                if (is_end) break;

                for (int j = 0; j < 4; j++) {
                    int nx = x + dx[j], ny = y + dy[j];
                    if (nx < 0 || nx >= r || ny < 0 || ny >= c || visited[nx][ny] || v[nx][ny] == 'X') continue;
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            if (is_end) break;
            cnt++;
        }
        if (is_end) cout << "Shortest Path: " << cnt << '\n';
        else cout << "No Exit\n";
    }
}