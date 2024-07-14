//숫자판 점프 - 실버 2

#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> v(5, vector<char>(5, ' '));
vector<vector<bool>> visited;
set<int> s;
string res = "";

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
    visited[x][y] = true;
    res += v[x][y];
    if (res.length() == 6) {
        s.insert(stoi(res));
        res.pop_back();
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)continue;
        dfs(nx, ny);
    }
    res.pop_back();
}


int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            visited.assign(5, vector<bool> (5, false));
            dfs(i, j);
        }
    }

    cout << s.size();


}