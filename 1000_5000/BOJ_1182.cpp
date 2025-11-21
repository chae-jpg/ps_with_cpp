// 부분수열의 합 - 실버 2

#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int n, s, t;

int cnt = 0;

void backtrack(int cur, int i) {
    if (cur == s) cnt++;
    if (i == n-1) return;
    i++;
    for (; i < n; i++) {
        backtrack(cur + v[i], i);
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        backtrack(v[i], i);
    }
}

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> t;
        v.push_back(t);
    }

    sort(v.begin(), v.end());
    solve();
    cout << cnt;


}