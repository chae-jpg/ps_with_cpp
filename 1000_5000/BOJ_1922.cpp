#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

vector<int> link;
vector<int> len;
int n, m;
vector<vector<int>> edge;

int find(int a) {
    while (a != link[a]) a = link[a];
    return a;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (len[a] < len[b]) swap(a, b);
    len[a] += len[b];
    link[b] = a;
}



int main() {
    cin >> n >> m;
    link.assign(n+1, 0);
    for (int i = 1; i <= n; i++) link[i] = i;
    len.assign(n+1, 1);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        edge.push_back({c, a, b});
    }

    sort(edge.begin(), edge.end());

    int ans = 0;

    for (auto e : edge) {
        int w = e[0], a = e[1], b = e[2];

        if (!same(a, b)) {
            unite(a, b);
            ans += w;
        }
    }
    cout << ans;
}