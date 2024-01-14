//열 개씩 끊어 출력하기 - 브론즈 3

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int len = s.length();

    for (int i = 0; i < ((len-1) / 10) + 1; i++) {
        for (int j = i * 10; j < (i+1) * 10; j++){
            if (s[j]== 0) break;
            cout << s[j];
        }
        if (i == ((len-1)/10)) continue;
        cout << '\n';
    }
}