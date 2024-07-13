//LCS 2 - 골드 4

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<int>> dp(s1.size() + 1, vector<int> (s2.size() + 1, 0));
    vector<vector<pi>> idx(s1.size() + 1, vector<pi> (s2.size() + 1, {0, 0}));

    for (int i = 1; i <= s1.size(); i++) {
        for (int j =1; j <= s2.size(); j++){
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1]+ 1;
                idx[i][j] = {i-1, j-1};
            } else {
                if (dp[i][j-1] > dp[i-1][j]) {
                    dp[i][j] = dp[i][j-1];
                    idx[i][j] = {i, j-1};
                } else {
                    dp[i][j] = dp[i-1][j];
                    idx[i][j] = {i-1, j};
                }
            }
        }
    }

    pi cur = {s1.size(), s2.size()};
    string ans = "";
    while (cur != make_pair(0, 0)) {
        if (idx[cur.first][cur.second].first == cur.first-1 && idx[cur.first][cur.second].second == cur.second-1) {
            ans += s1[cur.first-1];
        }
        cur = idx[cur.first][cur.second];
    }

    cout << dp[s1.size()][s2.size()] << '\n';
    if (dp[s1.size()][s2.size()]) {
        reverse(ans.begin(), ans.end());
        cout << ans;
    }

}