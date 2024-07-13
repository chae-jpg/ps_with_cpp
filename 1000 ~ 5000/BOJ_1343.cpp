//폴리오미노 - 실버 5

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, ans = "";
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '.') {
            if (cnt%2) {
                cout << -1;
                return 0;
            }
            for (int i = 0; i < cnt / 4; i++) {
                ans += "AAAA";
            }
            for (int i = 0; i < (cnt%4)/2; i++) {
                ans += "BB";
            }
            cnt = 0;
            ans += '.';
        }
        else cnt++;
    }
    if (cnt%2) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < cnt / 4; i++) {
        ans += "AAAA";
    }
    for (int i = 0; i < (cnt%4)/2; i++) {
        ans += "BB";
    }

    cout << ans;

}