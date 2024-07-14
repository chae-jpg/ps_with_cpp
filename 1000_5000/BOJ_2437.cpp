// 저울 - 골드 2

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;

int solve() {
    if (v[0] != 1) return 1;

    int sum = v[0];

    for (int i = 1; i < n; i++) {
        if (sum+1 >= v[i]) sum+= v[i];
        else break;
    }
    return sum + 1;
}

int main() {
    cin >> n;
    v.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    cout << solve();
}