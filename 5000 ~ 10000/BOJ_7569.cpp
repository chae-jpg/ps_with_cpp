//토마토 - 골드 5

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> ti;

int m, n, h;
vector<vector<vector<int>>> arr;

bool check(int x, int y, int z) {
    if (x < 0 || x >= h || y <0 || y >= n || z < 0 || z >= m) return false;
    if (arr[x][y][z] != 0) return false;
    return true;
}



int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    int non_rape = 0;
    int level = 0;
    queue<ti> q;
    cin >> m >> n >> h;
    arr.assign(h, vector<vector<int>> (n, vector<int> (m, 0)));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> arr[i][j][k];
                if (!arr[i][j][k]) non_rape++;
                else if (arr[i][j][k] == 1) q.push(make_tuple(i, j, k));
            }
        }
    }
    if (!non_rape) {
        cout << 0;
        return 0;
    }

    while (!q.empty()) {
        int cnt = q.size();

        int dx[6] = {1, -1, 0, 0, 0, 0}, dy[6] = {0, 0, 1, -1, 0, 0}, dz[6] = {0, 0, 0, 0, 1, -1};
        for (int i = 0; i < cnt; i++) {
            ti top = q.front();
            q.pop();

            for (int j = 0; j < 6; j++) {
                int nx = get<0>(top) + dx[j];
                int ny = get<1>(top) + dy[j];
                int nz = get<2>(top) + dz[j];
                if (check(nx, ny, nz)) {
                    q.push(make_tuple(nx, ny, nz));
                    arr[nx][ny][nz] = 1;
                    non_rape--;
                }
            }

        }
        level++;
        if (!non_rape) break;
    }
    if (non_rape) cout << -1;
    else cout << level;
}