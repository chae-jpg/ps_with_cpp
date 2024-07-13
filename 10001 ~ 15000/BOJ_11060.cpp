//점프 점프 - 실버 2

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9+7;

int main() {
    int n;
    cin >> n;
    vector<int> v(n, 0), dp(n, INF);

    for (int i= 0; i < n; i++) {
        cin >> v[i];
    }
    dp[0] = 0;

    for (int i = 0; i < n-1; i++) {
        if (!v[i]) continue;
           for (int j = 1; j <= v[i]; j++) {
           if (i+j < n) {
               dp[i+j] = min(dp[i+j], dp[i]+1);
           }
       }


    }
    if (dp[n-1] == INF) cout << -1;
    else cout << dp[n-1];

}