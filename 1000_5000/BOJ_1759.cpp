//암호 만들기 - 골드 5

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

set<int> vowel_idx;
vector<char> answer;
vector<bool> visited;
int vowel_cnt = 0;

void backtrack(vector<char>& alp, int l, int cnt, int n) {
    if (cnt == l) {
        if (vowel_cnt && (l - vowel_cnt) >= 2) {
            for (char a : answer) {
                cout << a;
            }
            cout << '\n';
        }
        return;
    }
    for (int i = n; i < alp.size(); i++) {
        if (visited[i]) continue;
        visited[i] = true;
        if (vowel_idx.find(i) != vowel_idx.end()) {
            vowel_cnt++;
            answer.push_back(alp[i]);
            backtrack(alp, l, cnt + 1, i);
            answer.pop_back();
            vowel_cnt--;
        }
        else {
            answer.push_back(alp[i]);
            backtrack(alp, l, cnt + 1, i);
            answer.pop_back();
        }
        visited[i] = false;
    }
}

int main() {
    ios_base ::sync_with_stdio(false);
    cout.tie(NULL);

    int l, c;
    vector<char> alp;
    cin >> l >> c;
    alp.assign(c, ' ');
    visited.assign(c, false);

    for (int i = 0; i < c; i++) {
        cin >> alp[i];
    }
    sort(alp.begin(), alp.end());

    for (int i = 0; i < c; i++) {
        char a = alp[i];
        if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') {
            vowel_idx.insert(i);
        }
    }

    backtrack(alp, l, 0, 0);


}