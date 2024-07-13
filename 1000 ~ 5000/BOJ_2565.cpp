//전깃줄 - 골드 5

#include <bits/stdc++.h>

using namespace std;

int n, max_n = 0, max_l  = 0;
vector<int> arr, dp;

void solve() {
    for (int i = 1; i <= max_n; i++) {
        if (!arr[i]) continue;
        for (int j = 1; j < i; j++) {
            if (!arr[j]) continue;
            if (arr[j] < arr[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
        max_l = max(max_l, dp[i]);
    }
}

int main() {
    cin >> n;
    arr.assign(501, 0);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr[a] = b;
        max_n = max(a, max_n);
    }
    dp.assign(max_n + 1, 1);

    solve();

    cout << n - max_l;
}