//아기 상어 - 골드 3

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

//상, 좌, 하, 우
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

vector<vector<int>> board;

int n, fish_cnt = 0, shark_size = 2, eat_cnt = 0;
pi shark_cur;

bool comp(pi a, pi b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int solve() {
    int ans = 0;
    while (fish_cnt) {
        queue<pi> q;
        bool found = false;
        q.push(shark_cur);
        int time = 0;
        vector<vector<bool>> visited (n, vector<bool> (n, false));
        while (!q.empty()) {
            vector<pi> possible;
            int len = q.size();
            time++;
            for (int j = 0; j < len; j++) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                visited[x][y] = true;
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;
                    if (board[nx][ny]) {
                        //나보다 큰 물고기 -> 못 지나감
                        if (board[nx][ny] > shark_size) continue;
                        if (board[nx][ny] < shark_size) {
                            possible.push_back({nx, ny});
                        }
                    }
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            //나보다 작은 물고기 -> 먹고 그 쪽으로 이동, 만약 먹은 개수 차면 크기 키워주기
            if (!possible.empty()) {
                sort(possible.begin(), possible.end(), comp);
                pi next = possible[0];
                ans += time;
                shark_cur = next;
                board[next.first][next.second] = 0;
                eat_cnt++;
                if (eat_cnt == shark_size) {
                    eat_cnt = 0;
                    shark_size++;
                }
                fish_cnt--;
                found = true;
            }
            if (found) break;
        }
        if (!found && fish_cnt) return ans;
    }
    return ans;
}

int main() {
    cin >> n;
    board.assign(n, vector<int> (n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                shark_cur = {i, j};
                board[i][j] = 0;
            }
            else if (board[i][j]) fish_cnt++;
        }
    }

    cout << solve();


}