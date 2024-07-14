#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> board;
vector<vector<bool>> visited;
int n;

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

void dfs(int h, int x, int y) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] <= h || visited[nx][ny]) continue;
        dfs(h, nx, ny);
    }
}

int main() {
    cin >> n;
    int max_h = -1, max_cnt = -1;
    board.assign(n, vector<int> (n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            max_h = max(max_h, board[i][j]);
        }
    }

    for (int i = 0; i <= max_h; i++) {
        visited.assign(n, vector<bool> (n, false));
        int cnt = 0;
        for (int x= 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (visited[x][y] || board[x][y] <= i) continue;
                dfs(i, x, y);
                cnt++;
            }
        }
        max_cnt = max(max_cnt, cnt);
    }

    cout << max_cnt;
}