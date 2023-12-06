//거짓말 - 골드 4

#include <iostream>
#include <vector>

using namespace std;

vector<int> parent, truth;
vector<vector<int>> party;

int find(int n) {
    if (parent[n] == n) return n;

    return parent[n] = find(parent[n]);
}

void unionF(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) parent[b] = a;
}

int main() {
    int n, m, t, cnt = 0;

    cin >> n >> m;
    parent.assign(n+1, 0);
    party.assign(m, vector<int> ());
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int a; cin >> a;
    while (a--) {
        cin >> t;
        truth.push_back(t);
    }

    for (int j = 0; j < m; j++) {
        cin >> a;
        for (int i = 0; i < a; i++) {
            cin >> t;
            party[j].push_back(t);
        }
        if (a > 1) {
            for (int i = 0; i < a-1; i++) {
                unionF(party[j][0], party[j][i+1]);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        bool flag = true;
        for (int t : truth) {
            if (find(t) == find(party[i][0])) {
                flag = false;
                break;
            }
        }
        if (flag) cnt++;
    }
    cout << cnt;

}