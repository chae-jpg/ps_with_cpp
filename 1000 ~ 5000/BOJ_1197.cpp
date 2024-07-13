// 최소 스패닝 트리 - 골드 4

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

vector<bool> visited;

int prim(const vector<vector<pi>>& graph) {
    int weight = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int top_node = pq.top().second;
        int top_dist = pq.top().first;
        pq.pop();

        if (visited[top_node]) continue;

        visited[top_node] = true;
        weight += top_dist;

        for (pi edge: graph[top_node]) {
            if (visited[edge.second]) continue;
            pq.push(edge);
        }


    }

    return weight;
}

int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<pi>> graph;
    graph.assign(v + 1, vector<pi>());
    visited.assign(v + 1, false);

    for (int i = 0; i < e; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({w, b});
        graph[b].push_back({w, a});
    }
    cout << prim(graph);
}