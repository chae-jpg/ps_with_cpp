//공항 - 골드 2

#include <bits/stdc++.h>

using namespace std;

int g, p;

set<int> gate;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int cnt = 0;
    cin >> g >> p;

    for (int i = 1; i <= g; i++) {
        gate.insert(-i);
    }

    while(p--) {
        int t; cin >> t;
        auto iter = gate.lower_bound(-t);
        if (iter == gate.end()) {
            cout << cnt;
            return 0;
        }
        cnt++;
        gate.erase(iter);
    }
    cout << cnt;
}