//친구 네트워크 - 골드 2

#include <bits/stdc++.h>

using namespace std;

const int LIM = 200000;

int link[LIM+1], len[LIM+1];
map<string, int> name_idx;
int idx;

int find(int x) {
    if (x == link[x]) return x;
    return link[x] = find(link[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return;
    if (len[a] > len[b]) swap(a, b);
    link[a] = b;
    len[b] += len[a];
}

void init() {
    for (int i = 1; i <= LIM; i++) {
        link[i] = i;
        len[i] = 1;
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a, b;
        int x, y;
        cin >> a >> b;

        if(name_idx.find(a) == name_idx.end()) name_idx[a] = idx++;
        x = name_idx[a];
        if(name_idx.find(b) == name_idx.end()) name_idx[b] = idx++;
        y = name_idx[b];

        unite(x, y);
        cout << len[find(x)] << '\n';
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        init();
        name_idx.clear();
        idx = 1;
        solve();

    }
}