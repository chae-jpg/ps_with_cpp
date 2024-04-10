//나무 재테크 - 골드 3

#include <bits/stdc++.h>

using namespace std;

int n, m, k;

vector<vector<int>> nutrient;
vector<vector<vector<int>>> tree;
vector<vector<int>> nu_amount;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int solve() {
    int cnt = 0;

    //봄
    for (int i= 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sort(tree[i][j].begin(), tree[i][j].end());
            for (int h = 0; h < tree[i][j].size(); h++) {
                if (tree[i][j][h] > nutrient[i][j]) tree[i][j][h]*=-1;
                else {
                    nutrient[i][j] -= tree[i][j][h];
                    tree[i][j][h]++;
                }
            }
        }
    }
    //여름
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int h = 0; h < tree[i][j].size(); h++) {
                if (tree[i][j][h] < 0) {
                    nutrient[i][j] += -(tree[i][j][h])/2;
                    tree[i][j].erase(tree[i][j].begin()+h);
                    h--;
                }
            }
        }
    }
    //가을
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int h = 0; h < tree[i][j].size(); h++) {
                if (tree[i][j][h]%5 == 0) {
                    int x = i, y = j;
                    for (int i = 0; i < 8; i++) {
                        int nx = x + dx[i], ny = y + dy[i];

                        if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
                        tree[nx][ny].push_back(1);
                    }
                }
            }
        }
    }
    //겨울
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            nutrient[i][j] += nu_amount[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cnt += tree[i][j].size();
        }
    }

    return cnt;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;
    nutrient.assign(n+1, vector<int> (n+1, 5));
    nu_amount.assign(n+1, vector<int> (n+1, 0));
    tree.assign(n+1, vector<vector<int>> (n+1, vector<int>()));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> nu_amount[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        tree[x][y].push_back(z);
    }
    int ans;
    while (k--) {
        ans = solve();
    }
    cout << ans;
}