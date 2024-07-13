#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int main() {
    int n;
    cin >> n;
    vector<int> dp(n+2, 0);
    vector<pi> v(n+1, {0, 0});

    for (int i = 1; i <= n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int next = v[i].first, w = v[i].second;
        dp[i] = max(dp[i-1], dp[i]);
        if (i + next <= n+1) {
            dp[i+next] = max(dp[i+next], dp[i]+w);
        }
    }
    cout << max(dp[n], dp[n+1]);
}