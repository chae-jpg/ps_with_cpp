//앱 - 골드 3

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

const int INF = 1e9+7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pi> v(n+1, {0, 0});

    for (int i = 1; i <= n; i++) {
        cin >> v[i].first;
    }
    for (int i = 1; i <= n; i++) {
        cin >> v[i].second;
    }
    sort(v.begin(), v.end());

    vector<int> dp(m+1, INF);

    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int cur = v[i].first, cost = v[i].second;
        int w;
        for (w = m; w >= 0; w--) {
            if (cur >= w) dp[w] = min(dp[w], cost);
            else {
                if (dp[w-cur] == INF) continue;
                dp[w] = min(dp[w], dp[w-cur] + cost);
            }
        }
    }

    cout << dp[m];
}