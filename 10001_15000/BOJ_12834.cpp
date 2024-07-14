//주간 미팅 - 골드 4

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

const int INF = 1e9+7;

int n, v, e, a, b;

vector<vector<pi>> graph;
vector<int> home;

int solve(int node) {
    int start = home[node];
    vector<int> dist(v+1, INF);
    vector<bool> visited(v+1, false);
    dist[start] = 0;
    priority_queue<pi> pq;

    //dist, node
    pq.push({0, start});

    while (!pq.empty()) {
        pi top = pq.top();
        pq.pop();
        int cur = top.second;
        if (visited[cur]) continue;
        visited[cur] = true;
        for (auto u : graph[cur]) {
            int next = u.first, w = u.second;
            dist[next] = min(dist[next], dist[cur] + w);
            pq.push({-dist[next], next});
        }
    }
    int ans = 0;
    if (dist[a] == INF) ans += -1;
    else ans += dist[a];
    if (dist[b] == INF) ans += -1;
    else ans += dist[b];
    return ans;
}

int main() {
    cin >> n >> v >> e;
    graph.assign(v+1, vector<pi> ());
    home.assign(n, 0);
    cin >> a >> b;

    for (int i = 0; i < n; i++) {
        cin >> home[i];
    }
    for (int i = 0; i < e; i++) {
        int x, y, z; cin >> x >> y >> z;
        graph[x].push_back({y, z});
        graph[y].push_back({x, z});
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += solve(i);
    }
    cout << sum;
}