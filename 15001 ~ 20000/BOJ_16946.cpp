//벽 부수고 이동하기 4 - 골드 2

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int n, m;
vector<vector<bool>> graph;
vector<vector<int>> ans;
vector<pi> blank;
vector<pi> wall;
map<pi, int> cnt_m;
vector<vector<pi>> link;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

pi find (pi x) {
    while (x != link[x.first][x.second]) x = link[x.first][x.second];
    return x;
}

void unite(pi a, pi b) {
    a = find(a);
    b = find(b);
    link[b.first][b.second] = a;
}

void setBlank() {
    vector<vector<bool>> visited(n, vector<bool> (m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            link[i][j] = {i, j};
        }
    }

    for (auto cur : blank) {
        if (visited[cur.first][cur.second]) continue;
        queue<pi> q;
        int cnt = 1;
        q.push(cur);

        while (!q.empty()) {
            pi p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            visited[x][y] = true;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || graph[nx][ny] || visited[nx][ny]) continue;
                visited[nx][ny] = true;
                q.push({nx, ny});
                cnt++;
                unite(cur, {nx, ny});
            }

        }
        cnt_m[cur] = cnt;
    }
}

void setAns() {
    for (auto cur : wall) {
        set<pi> visited;
        int cnt = 1;
        int x = cur.first, y = cur.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny <0 || ny >= m || graph[nx][ny]) continue;
            pi p = find({nx, ny});
            if (!visited.empty() && visited.find(p) != visited.end()) continue;
            cnt += cnt_m[p];
            visited.insert(p);
        }
        cnt %= 10;
        ans[x][y] = cnt;
    }


}

void solve() {
    setBlank();
    setAns();
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    graph.assign(n, vector<bool> (m, 0));
    ans.assign(n, vector<int> (m, 0));
    link.assign(n, vector<pi> (m, {0, 0}));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            (c-'0') ? wall.push_back({i, j}) : blank.push_back({i, j});
            graph[i][j] = c - '0';
        }
    }
    solve();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }

}