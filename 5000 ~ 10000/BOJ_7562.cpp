//나이트의 이동 - 실버 1

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int t, l, cnt;
pi coor, target;


void solve() {


}

int main() {
    cin >> t;
    while (t--) {
        bool flag = false;
        cin >> l;
        vector<vector<bool>> visited(l+1, vector<bool> (l+1, false));
        cin >> coor.first >> coor.second >> target.first >> target.second;

        cnt = 0;
        int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2}, dy[8] = {-2, 2, -1, 1, -2, 2, -1, 1};
        queue<pi> q;
        q.push(coor);
        visited[coor.first][coor.second] = true;

        while (!q.empty()) {
            int len = q.size();
            for (int k = 0; k < len; k++) {
                pi c = q.front();
                q.pop();
                int x = c.first, y = c.second;
                if (x == target.first && y == target.second) {
                    flag = true;
                    break;
                }
                for (int i = 0; i < 8; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || nx >= l || ny < 0 || ny >= l || visited[nx][ny]) continue;
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            if (flag) break;
            cnt++;
        }

        cout << cnt << '\n';
    }
}