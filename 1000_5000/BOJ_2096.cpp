// 내려가기 - 골드 5

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> curmin(3, 0), curmax(3, 0), dpmin(3, 0), dpmax(3, 0), cur(3, 0);

    for (int i = 0; i < 3; i++) {
        cin >> curmin[i];
        curmax[i] = curmin[i];
    }

    for (int i = 1; i < n; i++) {
        cin >> cur[0] >> cur[1] >> cur[2];

        dpmin[0] = min(curmin[0], curmin[1]) + cur[0];
        dpmin[1] = min({curmin[0], curmin[1], curmin[2]}) + cur[1];
        dpmin[2] = min(curmin[1], curmin[2]) + cur[2];
        dpmax[0] = max(curmax[0], curmax[1]) + cur[0];
        dpmax[1] = max({curmax[0], curmax[1], curmax[2]}) + cur[1];
        dpmax[2] = max(curmax[1], curmax[2]) + cur[2];
        curmin = dpmin;
        curmax = dpmax;
    }

    int min_ans = 1e9+7, max_ans = -1;
    for (int i = 0; i < 3; i++) {
        min_ans = min(min_ans, curmin[i]);
        max_ans = max(max_ans, curmax[i]);
    }
    cout << max_ans << ' ' << min_ans;
}