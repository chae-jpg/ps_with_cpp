//가장 긴 증가하는 부분 수열 4 - 골드 4

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int main() {
    int n, max_len = 0, max_idx;
    vector<int> arr;
    vector<int> dp;
    vector<int> idx;
    cin >> n;
    arr.assign(n+1, 0);
    dp.assign(n+1, 0);
    idx.assign(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j]+1;
                    idx[i] = j;
                }
            }
        }
        if (max_len < dp[i]) {
            max_len = dp[i];
            max_idx = i;
        }
    }
    cout << max_len << '\n';
    vector<int> ans;
    int cur = max_idx;

    while (cur != 0) {
        ans.push_back(arr[cur]);
        cur = idx[cur];
    }
    for (int i = max_len - 1; i >= 0; i--) cout << ans[i] << ' ';
}