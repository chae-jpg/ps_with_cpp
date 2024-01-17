//次の文字 - 브론즈 3

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;

    cin >> n >> s;

    for (int i = 1; i < n; i++) {
        if (s[i] == 'J') cout << s[i-1] << '\n';
    }



}