// 부분합 - 골드 4

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int l = 0, r = 0;

    if (l >= s) {
        cout << 1;
        return 0;
    }
    long long sum = v[l];
    int max_len = 1e5+1, len;
    while (l <= r && r < n) {
        if (sum < s) {
            r++;
            sum += v[r];
        }
        else if (sum >= s) {
            len = r - l + 1;
            max_len = min(len, max_len);
            sum -= v[l];
            l++;
        }

    }
    if (max_len == 1e5+1) cout << 0;
    else cout << max_len;
}