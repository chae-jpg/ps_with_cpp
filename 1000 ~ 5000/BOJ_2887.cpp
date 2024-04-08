//행성 터널 - 플래티넘 5

#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> coor;
vector<vector<int>> dist;
vector<int> link, len;

bool comp_x(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}

bool comp_y(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

bool comp_z(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];
}

int find (int node) {
    while(node != link[node]) node = link[node];
    return node;
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (len[a] < len[b]) swap(a, b);
    link[b] = a;
    len[a] += len[b];
}

long long solve() {
    long long ans = 0;
    int cnt = 0;
    link.assign(n, 0);
    len.assign(n, 1);
    for (int i = 0; i < n; i++) {
        link[i] = i;
    }

    for (auto cur : dist) {
        int a = cur[1], b = cur[2];
        if (find(a) == find(b)) continue;

        unite(a, b);
        ans += (long long)cur[0];
        cnt++;
        if (cnt == n-1) break;
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        coor.push_back({a, b, c, i});
    }
    sort(coor.begin(), coor.end(), comp_x);

    for (int i = 0; i < n-1; i++) {
        auto a = coor[i], b = coor[i+1];
        dist.push_back({abs(a[0] - b[0]), a[3], b[3]});
    }

    sort(coor.begin(), coor.end(), comp_y);

    for (int i = 0; i < n-1; i++) {
        auto a = coor[i], b = coor[i+1];
        dist.push_back({abs(a[1] - b[1]), a[3], b[3]});
    }

    sort(coor.begin(), coor.end(), comp_z);

    for (int i = 0; i < n-1; i++) {
        auto a = coor[i], b = coor[i+1];
        dist.push_back({abs(a[2] - b[2]), a[3], b[3]});
    }
    sort(dist.begin(), dist.end());

    cout << solve();
}