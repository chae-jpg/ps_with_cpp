//해킹 - 골드 4

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9+7;
typedef pair<int, int> pi;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, d, c;
        cin >> n >> d >> c;
        vector<vector<pi>> graph(n+1, vector<pi>());
        vector<int> dist(n+1, INF);
        vector<bool> visited(n+1, false);
        for (int i = 0; i < d; i++) {
            int a, b, s;
            cin >> a >> b >> s;
            graph[b].push_back({a, s});
        }

        dist[c] = 0;
        priority_queue<pi> pq;
        pq.push({0, c});

        while (!pq.empty()) {
            pi top = pq.top();
            pq.pop();
            int v = top.second;
            for (pi p : graph[v]) {
                if(visited[p.first]) continue;
                if (dist[p.first] > -top.first + p.second) {
                    dist[p.first] = -top.first + p.second;
                    pq.push({-dist[p.first], p.first});
                }
            }
        }
        int cnt = 0, max_time = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] != INF) {
                cnt++;
                max_time = max(dist[i], max_time);
            }
        }
        cout << cnt << ' ' << max_time << '\n';
    }
}