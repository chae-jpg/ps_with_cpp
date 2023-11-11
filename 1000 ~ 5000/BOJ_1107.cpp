//리모컨 - 골드 5

#include <iostream>
#include <set>
#include <cmath>
#include <string>

using namespace std;

#define MAX_CH 500000

int main() {
    int n, m, t, cnt = 0;
    char temp;
    bool flag = false;
    set<int> broken;
    cin >> n >> m;

    cnt = abs(100-n);

    if (!m) {
        int l = to_string(n).length();
        cout << min(l, cnt);
        return 0;
    }
    for (int i = 0; i < m; i++) {
        cin >> t;
        broken.insert(t);
    }



    t = n;
    while (t > 0) {
        t--;
        string s = to_string(t);
        int l = s.length();
        for (int i = 0; i < l; i++) {
            if (broken.find(s[i] - '0') != broken.end()) {
                flag = true;
                break;
            }
        }
        if (flag) {
            flag = false;
            continue;
        }
        cnt = min(abs(t - n) + l, cnt);
    }

    t = n-1;
    while (t < MAX_CH * 2) {
        t++;
        string s = to_string(t);
        int l = s.length();
        for (int i = 0; i < l; i++) {
            if (broken.find(s[i] - '0') != broken.end()) {
                flag = true;
                break;
            }
        }
        if (flag) {
            flag = false;
            continue;
        }
        cnt = min(abs(t - n) + l, cnt);
    }
    cout << cnt;
}