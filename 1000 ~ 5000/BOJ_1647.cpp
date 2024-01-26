//도시 분할 계획 - 골드 4

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

vector<vector<int>> edge;
vector<int> link, len;

int n, m;

int find(int n) {
    while (n != link[n]) n = link[n];
    return n;
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (len[a] < len[b]) swap(a, b);
    link[b] = a;
    len[a] += len[b];
}

int solve() {
    int sum = 0, max_w = -1;
    link.assign(n+1, 0);
    len.assign(n+1, 1);
    for (int i = 1; i <= n; i++) {
        link[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int a = edge[i][1], b = edge[i][2];
        if (find(a) != find(b)) {
            unite(a, b);
            sum += edge[i][0];
            max_w = max(edge[i][0], max_w);
        }
    }
    sum -= max_w;
    return sum;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({c, a, b});
    }
    sort(edge.begin(), edge.end());
    cout << solve();

}