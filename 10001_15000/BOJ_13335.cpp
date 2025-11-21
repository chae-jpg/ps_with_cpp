// 트럭 - 실버 1

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
int n, w, l;
vector<int> truck;

int solve() {
    int tw = 0, time = 0;
    deque<pi> cur;

    cur.push_back({0, truck.back()});
    tw += truck.back();
    truck.pop_back();


    while(!cur.empty()) {
        time++;
        // 1. 트럭 움직이기
        int len = cur.size();
        bool flag = false;
        for (int i = 0; i < len; i++) {
            pi t = cur[i];
            if (t.first == w) {
                tw -= t.second;
                flag = true;
            }
            else {
                cur[i].first++;
            }
        }
        if (flag) cur.pop_front();

        // 2. 새 트럭 넣기
        if (!truck.empty() && (cur.empty() || cur.back().first > 1) && tw + truck.back() <= l) {
            pi top = {1, truck.back()};
            cur.push_back(top);
            truck.pop_back();
            tw += top.second;
        }
    }
    return time;
}

int main() {
    cin >> n >> w >> l;
    truck.assign(n, 0);

    for (int i = n-1; i >= 0; i--) {
        cin >> truck[i];
    }
    cout << solve();
}