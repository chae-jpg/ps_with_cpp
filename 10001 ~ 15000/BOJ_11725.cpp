// 트리의 부모 찾기 - 실버 2

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> parent;

void traverse (vector<vector<int>>& tree) {
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int top = q.front();
        q.pop();

        for (int i = 0; i < tree[top].size(); i++) {
            if (parent[tree[top][i]]) continue;
            q.push(tree[top][i]);
            parent[tree[top][i]] = top;
        }
    }
}

int main() {
    int n;
    vector<vector<int>> tree;
    cin >> n;
    tree.assign(n+1, vector<int> (0));
    parent.assign(n+1, 0);

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    traverse(tree);

    for (int i = 2; i <= n; i++) {
        cout << parent[i] << '\n';
    }

}