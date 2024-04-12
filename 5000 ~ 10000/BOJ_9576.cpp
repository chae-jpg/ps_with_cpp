//책 나눠주기 - 골드 2

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

bool comp(pi a, pi b) {
    if (a.second == b.second) return (a.second - a.first < b.second-b.first);
    return a.second > b.second;
}

int solve(int n, int m) {
    int cnt = 0;
    vector<pi> v;
    set<int> s;
    for (int i = 1; i <= n; i++) {
        s.insert(i);
    }

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < m; i++){
        int a = v[i].first, b = v[i].second;
        auto iter = lower_bound(s.begin(), s.end(), b);
        if (*iter > b) iter--;
        if (*iter && *iter <= b && *iter >= a) {
            cnt++;
            s.erase(*iter);
        }
    }

    return cnt;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << solve(n, m) << '\n';
    }
}