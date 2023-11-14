//뱀과 사다리 게임 - 골드 5

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

vector<bool> visited(101, false);
vector<pi> stair, snake;

int bfs() {
    int cnt = 0;
    queue<int> q;

    q.push(1);
    visited[1] = true;

    while(!q.empty()) {
        int len = q.size();
        for (int i = 0; i < len; i++) {
            int cur = q.front();
            q.pop();
            for (int i = 1; i <= 6; i++) {
                int next = cur + i;
                if (next == 100) return cnt;
                if (visited[next] || next > 100) continue;
                for (pi s : stair) {
                    if (s.first == next) {
                        q.push(s.second);
                        visited[next] = true;
                        visited[s.second] = true;
                        break;
                    }
                }
                if (visited[next]) continue;
                for (pi s : snake) {
                    if (s.first == next) {
                        q.push(s.second);
                        visited[next] = true;
                        visited[s.second] = true;
                        break;
                    }
                }
                if (visited[next]) continue;
                q.push(next);
                visited[next] = true;
            }
        }
        cnt++;
    }
    return 0;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    stair.assign(n, {0, 0});
    snake.assign(m, {0, 0});

    for (int i = 0; i <n; i++) {
        cin >> stair[i].first >> stair[i].second;
    }
    for (int i = 0; i < m; i++) {
        cin >> snake[i].first >> snake[i].second;
    }

    cout << bfs() + 1;
}