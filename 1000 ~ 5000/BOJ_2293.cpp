//동전 1 - 골드 5

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> val(n, 0), dp(k+1, 0);

    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    dp[0] = 1;
    for (int j = 0; j < n; j++) {
        int v = val[j];
        for (int i = 1; i <= k; i++) {
            if (i - v < 0) continue;
            dp[i] += dp[i - v];
        }
    }

    cout << dp[k];
}