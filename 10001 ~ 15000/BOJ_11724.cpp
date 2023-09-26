#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited;

void treeTraverse(vector<vector<int>>& tree, int node) {
    if (visited[node]) {
        return;
    }
    visited[node] = true;

    int len = tree[node].size();

    for (int i = 0; i < len; i++) {
        treeTraverse(tree, tree[node][i]);
    }
}

int main() {
    int n, m, a, b, cnt = 0;
    cin >> n >> m;
    vector<vector<int>> tree (n+1, vector<int>());
    visited.assign(n+1, false);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i]) {
            continue;
        }
        treeTraverse(tree, i);
        cnt++;
    }
    cout << cnt;
}