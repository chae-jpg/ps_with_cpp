// 순회강연 - 골드 3

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

bool comp(pi a, pi b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

int main() {
    int n;
    cin >> n;
    vector<pi> v;
    v.assign(n, {0, 0});
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), comp);

    int ans = 0;
    vector<int> time(10001, -1);

    for (int i = 0; i < n; i++) {
        pi next = v[i];
        int idx = next.second;
        while (time[idx] != -1 && idx > 0) idx--;
        if (idx > 0) {
            time[idx] = i;
            ans += next.first;
        }
    }
    cout << ans;
}
