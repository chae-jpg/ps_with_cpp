//개발자 지망생 구름이의 취업 뽀개기 - 실버 3

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

bool comp (pi a, pi b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main() {
    int n, ans = 0;
    cin >> n;
    vector<int> prob_cnt(6, 0);
    vector<pi> time;

    for (int i = 1; i <= 5; i++) {
        cin >> prob_cnt[i];
    }

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        time.push_back({a, b});
    }

    sort(time.begin(), time.end(), comp);

    vector<vector<int>> arr (6, vector<int>());

    for (auto p : time) {
        arr[p.first].push_back(p.second);
    }

    for (int i = 1; i <= 5; i++) {
        for (int j = 0; j < prob_cnt[i]; j++) {
            ans += arr[i][j];
        }
        ans += (arr[i][prob_cnt[i]-1] - arr[i][0]);
    }

    cout << ans + 240;
}