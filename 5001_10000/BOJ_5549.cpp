#include <iostream>
#include <vector>

using namespace std;

void dp(const vector<vector<char>>& input, vector<vector<vector<int>>>& cnt, int m, int n) {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < 3; k++) {
                cnt[i][j][k] = cnt[i-1][j][k] + cnt[i][j-1][k] - cnt[i-1][j-1][k];
            }

            switch(input[i][j]) {
                case 'J' :
                    cnt[i][j][0]++;
                    continue;
                case 'O' :
                    cnt[i][j][1]++;
                    continue;
                case 'I' :
                    cnt[i][j][2]++;
                    continue;
            }
        }
    }
}

void calcAnswer (const vector<vector<vector<int>>>& cnt, vector<int>& answer, int a, int b, int c, int d) {
    for (int i = 0; i < 3; i++) {
        answer[i] = cnt[c][d][i] - cnt[a-1][d][i] - cnt[c][b-1][i] + cnt[a-1][b-1][i];
    }
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int m, n, k, a, b, c, d;

    cin >> m >> n >> k;
    vector<vector<char>> input (m+1, vector<char> (n+1, ' '));
    vector<vector<vector<int>>> cnt (m+1, vector<vector<int>> (n+1, vector<int> (3, 0)));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> input[i][j];
        }
    }
    dp(input, cnt, m, n);

    while (k--) {
        cin >> a >> b >> c >> d;
        vector<int> answer (3, 0);
        calcAnswer(cnt, answer, a, b, c, d);
        for (int num : answer) {
            cout << num << ' ';
        }
        cout << '\n';
    }
}