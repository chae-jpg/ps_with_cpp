//좋은 문자열 만들기 - 골드 3

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        int len, l1 = 1e6, l2 = -1, r1 = 1e6, r2 = -1, cnt = 0, tcnt;
        string s;
        cin >> len >> s;

        if (len == 1 || len == 3) {
            cout << -1 << '\n';
            continue;
        }

        for (int i = 0; i < len; i++) {
            if (s[i] == '0') {
                l1 = min(i, l1);
                r1 = max(i, r1);
            } else {
                l2 = min(i, l2);
                r2 = max(i, r2);
            }
        }

        int gap = min({l1, l2, r1, r2});
        if (l1)
        for (int i = 0; i < l1; i++) {

        }
        for (int i = len - 1; i >= r2; i--) {

        }
    }
}