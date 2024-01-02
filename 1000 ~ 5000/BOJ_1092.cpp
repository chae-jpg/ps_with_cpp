// 배 - 골드 5
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> crane,cargo;

int solve() {
    int cnt = 0, loaded = 0;
    bool flag;
    if (cargo[m-1] > crane[n-1]) {
        return -1;
    }
    while (!cargo.empty()) {
        loaded = 0;
        flag = false;

        for (int i = cargo.size() - 1; i >= 0; i--) {
            if (loaded == n) break;
            for (int j = n-1-loaded; j >= 0; j--) {
                if (cargo[i] > crane[j]) continue;
                else {
                    loaded++;
                    cargo.erase(cargo.begin() + i);
                }
                break;
            }
        }

        cnt++;
    }
    return cnt;
}



int main() {
    cin >> n;
    crane.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> crane[i];
    }
    cin >> m;
    cargo.assign(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> cargo[i];
    }
    sort(crane.begin(), crane.end());
    sort(cargo.begin(), cargo.end());
    cout << solve();
}