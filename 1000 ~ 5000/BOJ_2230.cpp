// 수 고르기 - 골드 5

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int l = 0, r = 0;

    int ans = 2e9;
    while (l < v.size() && r < v.size()) {
        if (v[r]-v[l] >= m) {
            ans = min(ans, v[r]-v[l]);
            l++;
        }
        else {
            r++;

        }


    }

    cout << ans;
}