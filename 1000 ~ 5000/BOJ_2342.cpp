#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9+7;

int n;
vector<int> seq;
vector<vector<int>> dp;

int calcPow(int cur, int next) {
    if (cur == next) return 1;
    if (cur == 0) return 2;
    if (cur == 1) {
        if (next == 2) return 3;
        if (next == 3) return 4;
        if (next == 4) return 3;
    }
    if (cur == 2) {
        if (next == 1) return 3;
        if (next == 3) return 3;
        if (next == 4) return 4;
    }
    if (cur == 3) {
        if (next == 1) return 4;
        if (next == 2) return 3;
        if (next == 4) return 3;
    }
    if (cur == 4) {
        if (next == 1) return 3;
        if (next == 2) return 4;
        if (next == 3) return 3;
    }
}

pair<int, int> getCoor(int cur) {
    switch(cur) {
        case 0 :
            return make_pair(0, 0);
            break;
        case 1 :
            return make_pair(0, 1);
            break;
        case 2 :
            return make_pair(0, 2);
            break;
        case 3 :
            return make_pair(0, 3);
            break;
        case 4 :
            return make_pair(0, 4);
            break;
        case 5 :
            return make_pair(1, 2);
            break;
        case 6 :
            return make_pair(1, 3);
            break;
        case 7 :
            return make_pair(1, 4);
            break;
        case 8 :
            return make_pair(2, 3);
            break;
        case 9 :
            return make_pair(2, 4);
            break;
        case 10 :
            return make_pair(3, 4);
            break;

    }


}

int main() {
    int t;
    while (cin >>t && t) {
        seq.push_back(t);
    }
    n = seq.size();
    dp.assign(n+1, vector<int>(11, 0));

    dp[1][seq[0]] = 2;

    for (int i = 1; i < n; i++) {
        int cur = seq[i];
        for (int j = 0; j < 11; j++) {
            pair<int, int> coor = getCoor(j);
            if (coor.first != cur && coor.second != cur) continue;

            int score = INF;
            for (int k = 0; k < 11; k++) {
                if (!dp[i][k]) continue;
                pair<int, int> bef_coor = getCoor(k);
                if (bef_coor.first != seq[i-1] && bef_coor.second != seq[i-1]) continue;
                if (k == j) score = min(score, dp[i][k] + 1);
                else score = min(score, dp[i][k] + ((bef_coor.first != cur)? calcPow(bef_coor.first, cur) : calcPow(bef_coor.second, cur)));
            }
            dp[i+1][j] = score;
        }
    }
    int ans = INF;
    for (int i = 0; i < 11; i++) {
        if (!dp[n][i]) continue;
        ans = min(dp[n][i], ans);
    }

    cout << ans;

}