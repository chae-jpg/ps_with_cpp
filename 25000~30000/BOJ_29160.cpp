// 나의 FIFA 팀 가치는? - 실버 2

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

bool comp(pi a, pi b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main() {
    int n, k;
    vector<pi> ath;
    vector<int> val (12, 0);
    vector<priority_queue<int>> pqv (12);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        pqv[a].push(b);
    }

    while (k--) {
        // 선수 선발
        for (int i = 1; i <= 11; i++) {
            if (pqv[i].empty()) continue;
            int top = pqv[i].top();
            if (top > val[i]) {
                if (val[i] != 0) pqv[i].push(val[i]);
                val[i] = top;
                pqv[i].pop();
            }
        }
        // 가치 1 하락
        for (int i = 1; i <= 11; i++) {
            if (val[i] == 0) continue;
            val[i]--;
        }
        // 재선발
        for (int i = 1; i <= 11; i++) {
            if (pqv[i].empty()) continue;
            int top = pqv[i].top();
            if (top > val[i]) {
                if (val[i] != 0) pqv[i].push(val[i]);
                val[i] = top;
                pqv[i].pop();
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= 11; i++) {
        sum += val[i];
    }
    cout << sum;
}