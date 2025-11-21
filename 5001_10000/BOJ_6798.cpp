//Knight Hop - 실버 3

#include <bits/stdc++.h>

using namespace std;

int dx[8] = {-1, -1, -2, -2, 1, 1, 2, 2}, dy[8] = {2, -2, -1, 1, 2, -2, -1, 1};

typedef pair<int, int> pi;

int main() {
    pi start, end;
    cin >> start.first >> start.second >> end.first >> end.second;

    queue<pi> q; q.push(start);
    vector<vector<bool>> visited(9, vector<bool> (9, false));
    visited[start.first][start.second] = true;

    int cnt = 0;
    while (!q.empty()) {
        bool end_loop = false;
        int len = q.size();
        for (int i = 0; i < len; i++) {
            pi top = q.front();
            int x = top.first, y = top.second;
            q.pop();
            if (make_pair(x, y) == end) {
                end_loop = true;
                break;
            }
            for (int j = 0; j < 8; j++) {
                int nx = x + dx[j], ny = y + dy[j];

                if (nx <= 0 || nx > 8 || ny <= 0 || ny > 8 || visited[nx][ny]) continue;
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        if (end_loop) break;
        cnt++;
    }

    cout << cnt;

}