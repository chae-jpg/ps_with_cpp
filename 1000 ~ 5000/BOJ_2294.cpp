//동전 2 - 골드 5

#include <bits/stdc++.h>

using namespace std;

vector<int> val;

int dp(int n, int k) {
    vector<int> arr(k+1, 987654321);
    arr[0] = 0;

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            int v = val[j];
            if (i - v < 0) continue;
            arr[i] = min(arr[i], 1 + arr[i - v]);
        }
    }


    return (arr[k] != 987654321) ? arr[k] : -1;
}

int main() {
    int n, k;
    cin >> n >> k;
    val.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    cout << dp(n, k);
}