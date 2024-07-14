//치즈 - 골드 3

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int n, m;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};
vector<vector<bool>> graph;
vector<pi> blank;
set<pi> cheese;
vector<vector<pi>> link;
vector<vector<int>> len;
map<pi, bool> is_open;

pi find(pi x) {
    while (x != link[x.first][x.second]) x = link[x.first][x.second];
    return x;
}

void unite(pi a, pi b) {
    a = find(a);
    b = find(b);
    if (len[a.first][a.second] < len[b.first][b.second]) swap(a, b);
    if (is_open[b]) is_open[a] = true;
    link[b.first][b.second] = a;
}

void setBlank() {
    vector<vector<bool>> visited(n, vector<bool> (m, false));
    link.assign(n, vector<pi> (m, {0, 0}));
    len.assign(n, vector<int> (m, 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            link[i][j] = {i, j};
        }
    }

    is_open[{0, 0}] = true;
    for (auto cur : blank) {
        queue<pi> q;
        q.push(cur);

        while(!q.empty()) {
            pi p = q.front();
            q.pop();
            int x = p.first, y = p.second;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || graph[nx][ny] || visited[nx][ny]) continue;
                visited[nx][ny] = true;
                q.push({nx, ny});
                unite(cur, {nx, ny});
            }
        }
        if (find(cur) != make_pair(0, 0)) is_open[cur] = false;
    }
}

int solve() {
    //빈칸 집합 세팅
    setBlank();
    int time = 0;
    while (!cheese.empty()) {
        vector<pi> deleted;
        for (auto cur : cheese) {
            int cnt = 0;
            int x = cur.first, y = cur.second;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m || graph[nx][ny]) continue;
                pi p = find({nx, ny});
                if (is_open[p]) cnt++;
            }
            if (cnt >= 2) {
                deleted.push_back(cur);
            }

        }
        for (auto p : deleted) {
            cheese.erase(p);
            for (int i = 0; i < 4; i++) {
                int x = p.first, y = p.second;
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || graph[nx][ny]) continue;
                unite({nx, ny}, p);
            }
        }
        for (auto p : deleted) graph[p.first][p.second] = false;
        time++;
    }
    return time;
}


int main() {
    cin >> n >> m;
    graph.assign(n, vector<bool> (m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int n; cin >> n;
            if (!n) blank.push_back({i, j});
            else cheese.insert({i, j});
            graph[i][j] = n;
        }
    }

    cout << solve();

}