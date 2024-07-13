// 영상처리 - 실버 2

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<double>> v(n, vector<double> (m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            double r, g, b;
            cin >> r >> g >> b;
            v[i][j] = (r+g+b)/3;
        }
    }

    int t; cin >> t;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            if (v[i][j] >= t) v[i][j] = 255;
            else v[i][j] = 0;
        }
    }

    queue<pi> q;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j]) continue;
            if (!v[i][j]) continue;
            q.push({i, j});
            while(!q.empty()) {
                pi top = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int x = top.first + dx[k], y = top.second + dy[k];
                    if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || !v[x][y]) continue;
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
            cnt++;
        }
    }

    cout << cnt;
}