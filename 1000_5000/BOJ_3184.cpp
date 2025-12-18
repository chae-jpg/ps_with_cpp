// 양 - 실버 1

#include <bits/stdc++.h>

using namespace std;

int r, c;
int sheep = 0, wolf = 0;

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

vector<vector<char>> v;
vector<vector<bool>> visited;
void dfs(int i, int j) {
    if (i < 0 || i >= r || j < 0 || j >= c || visited[i][j] || v[i][j] == '#') return;
    if (v[i][j] == 'o') sheep++;
    if (v[i][j] == 'v') wolf++;

    visited[i][j] = true;

    for (int k = 0; k < 4; k++) {
        int nx = i + dx[k], ny = j + dy[k];
        dfs(nx, ny);
    }
}

int main() {
    int total_sheep = 0, total_wolf = 0;
    cin >> r >> c;
    v.assign(r, vector<char> (c, ' '));
    visited.assign(r, vector<bool> (c, false));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (visited[i][j]) continue;
            sheep = 0, wolf = 0;
            dfs(i, j);
            if (sheep <= wolf) {
                sheep = 0;
            } else {
                wolf = 0;
            }
            total_sheep += sheep;
            total_wolf += wolf;
        }
    }
    cout << total_sheep << ' ' << total_wolf;
}