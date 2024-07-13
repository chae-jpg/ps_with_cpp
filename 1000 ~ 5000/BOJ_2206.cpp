//벽 부수고 이동하기 - 골드 3

#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, bool> tib;

vector<vector<int>> arr;
queue<tib> q;
int cnt = 0;
int x[4] = {-1, 1, 0, 0}, y[4] = {0, 0, -1, 1};
int n, m;
vector<vector<bool>> visited;
bool possible;
void solve() {
    q.push({0, 0, false});

    while (!q.empty()) {
        int l = q.size();
        cnt++;
        for (int k = 0; k < l; k++) {
            tib cur = q.front();
            q.pop();
            int cx = get<0>(cur), cy = get<1>(cur);
            if (cx == n-1 && cy == m-1) {
                possible = true;
                return;
            }
            visited[cx][cy] = true;
            for (int i = 0; i < 4; i++) {
                bool flag = get<2>(cur);
                int nx = cx + x[i], ny = cy + y[i];
                if (nx <0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;
                if (arr[nx][ny] && flag) {
                    continue;
                }
                if (arr[nx][ny]) {
                    flag = true;
                }
                q.push({nx, ny, flag});
            }

        }


    }
}

int main() {
    cin >> n >> m;
    arr.assign(n, vector<int> (m, 0));
    visited.assign(n, vector<bool> (m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            arr[i][j] = c-'0';
        }
    }

    solve();
    if (!possible) cout << -1;
    else cout << cnt;


}