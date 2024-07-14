#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

vector<vector<int>> arr;
vector<vector<bool>> visited;

void bfs(int n, int m, int x, int y) {
    int move_x[4] = {-1, 1, 0, 0};  //상 하 좌 우
    int move_y[4] = {0, 0, -1, 1};  //상 하 좌 우

    queue<pi> q;
    q.push({x, y});
    visited[x][y] = true;
    arr[x][y] = 0;

    while (!q.empty()) {
        int current_x = q.front().first, current_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = current_x + move_x[i], next_y = current_y + move_y[i];
            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && !visited[next_x][next_y] && arr[next_x][next_y]) {
                q.push({next_x, next_y});
                visited[next_x][next_y] = true;
                arr[next_x][next_y] = arr[current_x][current_y] + 1;
            }
        }

    }


}

int main() {
    int n, m, x, y;

    cin >> n >> m;
    arr.assign(n, vector<int> (m, 0));
    visited.assign (n, vector<bool> (m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                x = i;
                y = j;
            }
        }
    }
    bfs (n, m, x, y);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && arr[i][j]) {
                arr[i][j] = -1;
            }
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }



}