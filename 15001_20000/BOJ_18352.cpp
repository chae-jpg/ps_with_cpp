#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
const int INF = 987654321;

int n, m, k, x;
vector<vector<int>> graph;
vector<int> dist;
vector<bool> visited;

vector<int> solve() {
    priority_queue<pi> pq;
    dist[x] = 0;

    pq.push({0, x});

    while (!pq.empty()) {
        pi top = pq.top();
        pq.pop();
        int w = -top.first;
        int v = top.second;
        visited[v] = true;


        for (int next : graph[v]) {
            if (visited[next]) continue;
            dist[next] = min(dist[next], w + 1);
            pq.push({-dist[next], next});
            visited[next] = true;
        }

    }
    vector<int> ans;

    for (int i = 1; i <= n; i++) {
        if (dist[i] == k) ans.push_back(i);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    cin >> n >> m >> k >> x;
    graph.assign(n+1, vector<int> ());
    dist.assign(n+1, INF);
    visited.assign(n+1, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    vector<int> ans = solve();

    if (ans.empty()) {
        cout << -1;
        return 0;
    }

    for (int n : ans) {
        cout << n << '\n';
    }

}