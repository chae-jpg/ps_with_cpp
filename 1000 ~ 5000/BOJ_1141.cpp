// 접두사 - 실버 1

#include <bits/stdc++.h>

using namespace std;

bool comp(string a, string b) {
    return a.length() > b.length();
}

int main() {
    int n;
    vector<string> v;
    set<string> ans;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string t; cin >> t;
        v.push_back(t);
    }

    sort(v.begin(), v.end(), comp);

    ans.insert(v[0]);

    for (int i = 1; i < n; i++) {
        string s = v[i];
        if (ans.find(s) != ans.end()) continue;
        bool flag = true;
        for (auto iter = ans.begin(); iter != ans.end(); iter++) {
            bool diff_char = false;
            for (int j = 0; j < s.length(); j++) {
                if ((*iter)[j] != s[j]) {
                    diff_char = true;
                    break;
                }
            }
            if (!diff_char) flag = false;
        }
        if (flag) ans.insert(s);
    }
    cout << ans.size();
}