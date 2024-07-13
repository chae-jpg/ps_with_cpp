// 보석 도둑 - 골드 2

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

bool comp(pi a, pi b) {
    return a.second < b.second;
}

int main() {
    int n, k;
    long long sum = 0;
    vector<pi> jewel;
    priority_queue<int> bag;
    priority_queue<pi> jewel_rank;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        jewel.push_back({b, a});
    }
    sort(jewel.begin(), jewel.end(), comp);

    for (int i = 0; i < k; i++) {
        int a; cin >> a;
        bag.push(-a);
    }
    int idx = 0;
    while (!bag.empty()) {
        int top = -bag.top();
        bag.pop();
        for (; idx < jewel.size() && jewel[idx].second <= top; idx++) {
            jewel_rank.push(jewel[idx]);
        }
        if (jewel_rank.empty()) continue;
        sum += jewel_rank.top().first;
        jewel_rank.pop();
    }
    cout << sum;
}