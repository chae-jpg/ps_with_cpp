// 데스 나이트 - 실버 1

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int dx[6] = {-2, -2, 0, 0, 2, 2}, dy[6] = {-1, 1, -2, 2, -1, 1};

vector<vector<bool>> visited;

int main() {
    int n;
    cin >> n;
    visited.assign(n, vector<bool> (n, false));
    queue<pi> q;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    q.push({x1, y1});
    visited[x1][y1] = true;
    int cnt = 1;
    while (!q.empty()) {
        int len = q.size();
        for (int l = 0; l < len; l++) {
            pi top = q.front();
            q.pop();

            for (int i= 0; i < 6; i++) {
                int nx = top.first + dx[i], ny = top.second + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;
                if (nx == x2 && ny == y2) {
                    cout << cnt;
                    return 0;
                }
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        cnt++;
    }
    cout << -1;
}