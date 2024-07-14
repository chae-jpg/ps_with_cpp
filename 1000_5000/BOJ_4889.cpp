//안정적인 문자열 - 실버 1

#include <bits/stdc++.h>

using namespace std;

string str;

int main() {
    int turn = 1;
    while (cin >> str && str[0] != '-') {
        stack<char> s;
        int cnt = 0, l = 0, r = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '{') s.push('{');
            else {
                if (!s.empty() && s.top() == '{') s.pop();
                else s.push('}');
            }

        }

        while (!s.empty()) {
            if (s.top() == '{') l++;
            else r++;
            s.pop();
        }
        if (!l) cnt = r/2;
        else if (!r) cnt = l/2;
        else cnt = l/2 + r/2 + ((l) % 2) * 2;

        cout << turn << ". " << cnt << '\n';
        turn++;
    }
}