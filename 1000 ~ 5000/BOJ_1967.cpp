//트리의 지름 - 골드 4

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

int max_height = 0, sum = 0;

void traverse(vector<vector<pi>>& tree, int node) {
    if (!tree[node].size()) {
        max_height = max(sum, max_height);
        return;
    }
    for (int i = 0; i < tree[node].size(); i++) {
        sum += tree[node][i].second;
        traverse(tree, tree[node][i].first);
        sum -= tree[node][i].second;
    }
}

int main() {
    int n;
    // 행 : 부모노드, 원소 : {자식 노드, 가중치}
    vector<vector<pi>> tree;
    cin >> n;
    tree.assign(n + 1, vector<pi>(0));

    for (int i = 0; i < n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a].push_back({b, c});
    }

    traverse(tree, 1);
    cout << max_height;


}