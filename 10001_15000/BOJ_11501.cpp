// 주식 - 실버 2

#include <bits/stdc++.h>

using namespace std;

long long solve(int n, const vector<int>& v) {
    int idx = v[n-1];
    int cnt = 0;
    long long ans = 0;

    for (int i = n-1; i >= 0; i--) {
        if (idx < v[i]) {
            // 1. 이전 값들 더함
            for (int j = i+1; j <= i+cnt; j++) {
                ans += idx - v[j];
            }
            // 2. 새 idx, cnt로 갱신
            idx = v[i];
            cnt = 0;
        } else {
            cnt++;
        }
    }
    for (int j = 0; j < cnt; j++) {
        ans += idx - v[j];
    }

    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);

        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        cout << solve(n, v) << '\n';
    }




}