//연구소 - 골드 4

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int n, m;
vector<vector<int>> board;
vector<pi> blank, virus;
vector<int> check;


int backtrack(int idx, int cnt) {
    if (cnt == 3) {
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pi> q;
        int ori = blank.size() - 3;
        //벽 세우기
        for (int i = 0; i < 3; i++) {
            pi coor = blank[check[i]];
            board[coor.first][coor.second] = 1;
        }

        for (pi v : virus) {
            visited[v.first][v.second] = true;
            q.push(v);
        }

        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
        while (!q.empty()) {
            pi cur = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = cur.first + dx[i], ny = cur.second + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || board[nx][ny]) continue;
                visited[nx][ny] = true;
                ori--;
                q.push({nx, ny});
            }
        }
        //원복
        for (int i = 0; i < 3; i++) {
            pi coor = blank[check[i]];
            board[coor.first][coor.second] = 0;
        }
        return ori;
    }
    int safe = -1;
    for (int i = idx + 1; i < blank.size(); i++) {
        check.push_back(i);
        safe = max(safe, backtrack(i, cnt + 1));
        check.pop_back();
    }
    return safe;
}

int main() {
    int sum = -1;
    cin >> n >> m;
    board.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (!board[i][j]) {
                blank.push_back({i, j});
            }
            else if (board[i][j] == 2) {
                virus.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < blank.size()-1; i++) {
        check.push_back(i);
        sum = max(sum, backtrack(i, 1));
        check.pop_back();
    }

    cout << sum;
}