//녹색 옷 입은 애가 젤다지? - 골드 4

#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int n;
vector<vector<int>> graph;
vector<int> dist;
vector<bool> visited;

typedef pair<int, int> pi;

void solve() {
    priority_queue<pi> pq;
    int move[4] = {-1, 1, -n, +n};
    dist[0] = graph[0][0];
    pq.push({0, 0});

    while (!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();
        visited[cur] = true;
        for (int i = 0; i < 4; i++) {
            if (cur%n == n-1 && i == 1) continue;
            if (!(cur%n) && i == 0) continue;
            int next = cur + move[i];
            if (next < 0 || next >= n*n || visited[next]) continue;
            if (dist[next] > dist[cur] + graph[next/n][next%n]) {
                dist[next] = dist[cur] + graph[next/n][next%n];
                pq.push({-dist[next], next});
            }
        }


    }

}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int cnt = 1;
    while (cin >> n && n) {
        graph.assign(n,vector<int>(n, 0));
        dist.assign(n*n, INF);
        visited.assign(n*n, false);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> graph[i][j];
            }
        }
        solve();
        cout << "Problem " + to_string(cnt++) +": " + to_string(dist[n*n-1]) << '\n';
    }




}