//거짓말 - 골드 4

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int m;
vector<vector<int>> party_ppl, ppl_party;
vector<bool> can_join;
set<int> know_truth;

void search(int& lie_cnt, int p) {
    if (know_truth.find(p) != know_truth.end()) return;
    for (int party : ppl_party[p]) {
        if (can_join[party]){
            can_join[party] = false;
            lie_cnt++;
            for (int n : party_ppl[party]) {
                search(lie_cnt, n);
            }
        }

    }
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t, lie_cnt = 0, pn;

    cin >> n >> m;
    party_ppl.assign(m+1, vector<int>());
    ppl_party.assign(n+1, vector<int>());
    can_join.assign(m+1, true);

    int truth_cnt;
    cin >> truth_cnt;
    for (int i = 0; i < truth_cnt; i++) {
        cin >> t;
        know_truth.insert(t);
    }

    for (int i = 1; i <= m; i++) {
        cin >> pn;
        while (pn--) {
            cin >> t;
            party_ppl[i].push_back(t);
            ppl_party[t].push_back(i);
        }
    }

    for (auto iter = know_truth.begin(); iter != know_truth.end(); iter++) {
        for (int p : ppl_party[*iter]) {
            can_join[p] = false;
            lie_cnt++;
        }
    }

    for (int i = 1; i <= m; i++) {
        if (can_join[i]) continue;
        for (int p : party_ppl[i]) {
            search(lie_cnt, p);
        }
    }

    cout << (m - lie_cnt >= 0) ? m-lie_cnt : 0;
}