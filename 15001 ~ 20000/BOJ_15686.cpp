//치킨 배달 - 골드 5

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int n, m;
vector<pi> home, chicken;
vector<int> check;

int calcDist(int idx) {
    int sum = 101;
    for (int c : check) {
        pi c_coor = chicken[c], h_coor = home[idx];
        int t = abs(h_coor.first - c_coor.first) + abs(h_coor.second - c_coor.second);
        sum = min(sum ,t);
    }
    return sum;
}

int backtrack(int idx, int cnt) {
    if (cnt == m) {
        int sum = 0;
        for (int i = 0; i < home.size(); i++) {
            sum += calcDist(i);
        }
        return sum;
    }
    int min_sum = 100*13;
    for (int i = idx+1; i < chicken.size(); i++) {
        check.push_back(i);
        int result = backtrack(i, cnt+1);
        min_sum = min(min_sum, result);
        check.pop_back();
    }
    return min_sum;
}

int solve() {
    int sum = 100*13;

    for (int i = 0; i < chicken.size() - m + 1; i++) {
        check.push_back(i);
        sum = min(backtrack(i, 1), sum);
        check.pop_back();
    }

    return sum;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            int t; cin >> t;
            if (t == 1) home.push_back({i, j});
            else if (t == 2) chicken.push_back({i, j});
        }
    }

    cout << solve();

}