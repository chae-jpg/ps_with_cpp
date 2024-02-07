// 알파벳 - 골드 4

#include <bits/stdc++.h>

using namespace std;

vector<bool> visited(26, false);

int r, c;
vector<vector<char>> v;


int max_cnt = 0;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

void backtrack(int x, int y, int cnt) {
    visited[v[x][y]-'A'] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c || visited[v[nx][ny] - 'A']) {
            max_cnt = (nx < 0 || nx >= r || ny < 0 || ny >= c) ? max(cnt, max_cnt) : max(cnt+1, max_cnt);
            continue;
        }
        backtrack(nx, ny, cnt+1);
    }
    visited[v[x][y]-'A'] = false;

}

int main() {
    cin >> r >> c;
    v.assign(r, vector<char> (c));


    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> v[i][j];
        }
    }

    if (r == 1 && c == 1) {
        cout << 1;
        return 0;
    }

    visited[v[0][0] - 'A'] = true;
    backtrack(0, 0, 0);

    cout << max_cnt;
}