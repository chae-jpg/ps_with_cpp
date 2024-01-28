//행성 터널 - 플래티넘 5

#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> coor;
vector<vector<int>> dist;
vector<int> link, len;

int find (int n) {
    while(n != link[n]) n = link[n];
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
    int ans = 0;

    link.assign(n, 0);
    len.assign(n, 1);
    for (int i = 0; i < n; i++) {
       link[i] = i;
    }

    for (auto cur : dist) {
        int a = cur[1], b = cur[2];
        if (find(a) == find(b)) continue;

        unite(a, b);
        ans += cur[0];
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        coor.push_back({a, b, c});
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            auto a = coor[i], b = coor[j];
            dist.push_back({min({abs(a[0] - b[0]), abs(a[1] - b[1]), abs(a[2] - b[2])}), i, j});
        }
    }
    sort(dist.begin(), dist.end());

    cout << solve();
}