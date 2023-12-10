//트리 - 골드 5

#include <bits/stdc++.h>

using namespace std;

int n, d, cnt = 0, r;
vector<int> parent;

void solve(int i) {
    bool flag = false;
    for (int j = 0; j < n; j++) {
        if (parent[j] == i && j != d) {
            solve(j);
            flag = true;
        }
    }
    if (!flag) cnt++;
}

int main() {
    cin >> n;
    parent.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> parent[i];
        if (parent[i] == -1) r = i;
    }
    cin >> d;
    if (d == r) {
        cout << 0;
        return 0;
    }
    solve(r);

    cout << cnt;

}