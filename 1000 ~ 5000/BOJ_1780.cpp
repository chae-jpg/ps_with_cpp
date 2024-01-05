//종이의 개수 - 실버 2

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int n;
int cnt[3] = {0, 0, 0};
vector<vector<int>> paper;

void recur(pi l, int len) {
    int init = paper[l.first][l.second];
    bool flag = false;

    if (!len) return;

    for (int i = l.first; i < l.first + len; i++) {
        for (int j = l.second; j < l.second + len; j++) {
            if (paper[i][j] != init) {
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    if (!flag) cnt[init+1]++;
    else {
        len /= 3;
        recur(l, len);
        recur({l.first + len, l.second}, len);
        recur({l.first + len + len, l.second}, len);
        recur({l.first, l.second + len}, len);
        recur({l.first + len, l.second + len}, len);
        recur({l.first + len + len, l.second + len}, len);
        recur({l.first, l.second + len + len}, len);
        recur({l.first + len, l.second + len + len}, len);
        recur({l.first + len + len, l.second + len + len}, len);
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    paper.assign(n, vector<int> (n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }
    recur({0, 0}, n);

    for (int n : cnt) {
        cout << n << '\n';
    }
}