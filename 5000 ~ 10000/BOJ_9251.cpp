//LCS - 골드 5

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> len;
string s1, s2;

void solve() {
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if (s1[i-1] == s2[j-1]) {
                len[i][j] = len[i-1][j-1] + 1;
            } else len[i][j] = max(len[i-1][j], len[i][j-1]);
        }
    }
}

int main() {
    cin >> s1 >> s2;
    len.assign(s1.size()+1, vector<int> (s2.size()+1, 0));

    solve();

    cout << len[s1.size()][s2.size()];

}