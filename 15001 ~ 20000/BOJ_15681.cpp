#include <bits/stdc++.h>

using namespace std;

int n, r, q;
vector<vector<int>> graph;
vector<vector<int>> tree;
vector<bool> visited;
vector<int> cnt;

void makeTree(){
    queue<int> qi;
    qi.push(r);
    visited[r] = true;
    while (!qi.empty()) {
        int top = qi.front();
        qi.pop();

        for (int a : graph[top]) {
            if (visited[a]) continue;
            visited[a] = true;
            tree[top].push_back(a);
            qi.push(a);
        }
    }

}

void calcChild(int a) {
    for (int b : tree[a]) {
        calcChild(b);
        cnt[a] += cnt[b];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> r >> q;
    graph.assign(n+1, vector<int> ());
    tree.assign(n+1, vector<int> ());
    visited.assign(n+1, false);
    cnt.assign(n+1, 1);

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    makeTree();
    calcChild(r);

    while (q--){
        int a; cin >> a;
        cout << cnt[a] << '\n';
    }




}