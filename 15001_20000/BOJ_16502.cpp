//그녀를 찾아서 - 실버 3

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, double> pid;

int t, m;

vector<vector<pid>> graph;

int main() {
    cin >> t >> m;
    graph.assign(4, vector<pid>());

    for (int i = 0; i < m; i++) {
        char a, b;
        double c;
        cin >> a >> b >> c;
        graph[a-'A'].push_back({b-'A', c});
    }

    vector<vector<double>> dp(t+1, vector<double> (4, 0));


    for (int i = 0; i < 4; i++) {
        dp[0][i] = (double)1 / 4;
    }

    // 시간 : 1에서부터 t일 때까지 반복
    for (int i = 1; i <= t; i++) {
        for (int j = 0; j < 4; j++) {
            int cur = j;
            for (auto next : graph[cur]) {
                dp[i][next.first] += dp[i-1][cur] * next.second;
            }
        }
    }

    cout << setprecision(2) << fixed;
    for (int i = 0; i < 4; i++) {
        cout << dp[t][i] * 100 << '\n';
    }
}