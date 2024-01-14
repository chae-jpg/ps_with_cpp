//A와 B - 골드 5

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    while (s.length() < t.length()) {
        if (t[t.length() - 1] == 'A') t.erase(t.end() - 1);
        else if (t[t.length() - 1] == 'B') {
            t.erase(t.end() - 1);
            reverse(t.begin(), t.end());
        } else break;
    }
    if (s == t) cout << 1;
    else cout << 0;

}