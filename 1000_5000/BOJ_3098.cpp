//소셜네트워크 - 실버 1

#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<set<int>> graph;

int main() {
    cin >> n >> m;
    graph.assign(n+1, set<int> ());
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    int total = n*(n-1)/2;
    if (total == m) cout << 0;

    while (m != total) {
        int cnt = 0;
        for (int i = 1; i<= n; i++) {
            for (auto f : graph[i]) {
                for (auto ff : graph[f]) {
                    //친구의 친구가 내 친구가 아닐 때
                    if (graph[i].find(ff) == graph[i].end()) {
                        cnt++;
                        graph[i].insert(ff);
                    }
                }
            }
        }



    }

}