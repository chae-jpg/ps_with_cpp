//타임머신 - 골드 4

#include <bits/stdc++.h>

using namespace std;
const int INF = INT_MAX;
typedef pair<int, int> pi;

int n, m;
vector<vector<pi>> graph;
vector<long long> dist;
bool flag = false;

void solve() {
    dist[1] = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 1; j <= n; j++) {
            for (auto node : graph[j]) {
                if (dist[j] == INF) continue;
                dist[node.first] = min(dist[node.first], dist[j] + node.second);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto node : graph[i]) {
            if (dist[i] == INF) continue;
            if (dist[node.first] > dist[i] + node.second) {
                cout << -1;
                flag = true;
                return;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    graph.assign(n+1, vector<pi>());
    dist.assign(n+1, INF);

    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }
    solve();
    if (flag) return 0;
    for (int i = 2; i <= n; i++) {
        if (dist[i] == INF) cout << -1;
        else cout << dist[i];
        cout << '\n';
    }

}