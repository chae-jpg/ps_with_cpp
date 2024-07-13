#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<char>> v;
vector<vector<bool>> visited;
bool flag = false;

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
    if (visited[x][y]) return;
    visited[x][y] = true;
    if (x == n-1) {
        flag = true;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || v[nx][ny] == '1') continue;
        dfs(nx, ny);
    }
}

int main() {
    cin >> n >> m;
    v.assign(n,vector<char> (m, ' '));
    visited.assign(n, vector<bool> (m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        if (v[0][i] == '0') dfs(0, i);
        if (flag) break;
    }
    if (flag) cout << "YES";
    else cout << "NO";
}