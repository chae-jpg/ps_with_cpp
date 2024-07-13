//사이클 게임 - 골드 4

#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> link, len;

int find(int node) {
    if (link[node] == node) return node;
    return link[node] = find(link[node]);
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
    //link 초기화
    for (int i = 0; i < n; i++) {
        link[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (find(a) == find(b)) {
            ans = i+1;
            break;
        }
        unite(a, b);
    }

    return ans;

}


int main() {
    cin >> n >> m;

    link.assign(n+1, 0);
    len.assign(n+1, 1);

    cout << solve();

}