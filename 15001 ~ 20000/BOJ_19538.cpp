#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, t;
    vector<vector<int>> relation;
    vector<int> answer;
    vector<int> trust_cnt;
    vector<bool> trust;
    queue<int> check;

    cin >> n;
    relation.assign(n + 1, vector<int>(0));
    trust.assign(n+1, false);
    trust_cnt.assign(n+1, 0);
    answer.assign(n+1, 0);

    for (int i = 1; i <= n; i++) {
        while (cin >> t && t != 0) {
            relation[i].push_back(t);
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> t;
        trust[t] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (trust[i]) {
            int len = relation[i].size();
            for (int j = 0; j < len; j++) {
                trust_cnt[relation[i][j]]++;
                check.push(relation[i][j]);
            }
        }
    }
    while (!check.empty()) {
        int p = check.front();
        check.pop();
        if (trust[p]) {
            continue;
        }
        if (trust_cnt[p] >= (relation[p].size()+1) / 2) {
            trust[p] = true;

            for (int i = 0; i < relation[p].size(); i++) {
                if (trust[relation[p][i]]) continue;
                trust_cnt[relation[p][i]]++;
                check.push(relation[p][i]);
            }
        }

    }

    for (int i = 1; i <= n; i++) {
        if (!trust[i]) {
            answer[i] = -1;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << answer[i] << ' ';
    }
}