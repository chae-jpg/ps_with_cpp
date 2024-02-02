//전화번호 목록 - 골드 4

#include <bits/stdc++.h>

using namespace std;

bool comp(string a, string b) {
    return a.length() < b.length();
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<string> v;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            v.push_back(s);
        }
        sort(v.begin(), v.end(), comp);

        vector<vector<int>> trie(v[n-1].length() + 1, vector<int> (10, 0));

        for (auto s : v) {
            bool prev = true;
            int idx = 1;
            for (int i = 0; i < s.length(); i++) {
                char c = s[i];
                if (c == ' ') continue;
                if (trie[idx][c-'0'] == 0) prev = false;
                if (trie[idx][c-'0'] == 2 && prev) {
                    flag = false;
                    break;
                }
                trie[idx++][c-'0'] = 1;
            }
            trie[s.length()][s[s.length()-1]-'0'] = 2;
            if (!flag) break;
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }



}