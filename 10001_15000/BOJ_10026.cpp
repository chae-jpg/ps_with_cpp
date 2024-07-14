//적록색약 - 골드 5

#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> picture;
vector<vector<bool>> visited;
int normal_cnt = 0, blind_cnt = 0;

void dfs(int i, int j, int n) {
    int x[4] = {-1, 1, 0 ,0}, y[4] = {0, 0, -1, 1};
    visited[i][j] = true;

    for (int k = 0; k < 4; k++) {
        int new_x = i + x[k], new_y = j + y[k];

        if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && picture[i][j] == picture[new_x][new_y] && !visited[new_x][new_y]) {
            dfs(new_x, new_y, n);
        }
    }
}

bool blindCheck(char a, char b) {
    if (a == 'R') {
        if (b == 'B') return false;
    }
    else if (a == 'G') {
        if (b == 'B') return false;
    } else {
        if (b == 'R' || b == 'G') return false;
    }
    return true;
}

void blindDfs(int i, int j, int n) {
    int x[4] = {-1, 1, 0 ,0}, y[4] = {0, 0, -1, 1};
    visited[i][j] = true;

    for (int k = 0; k < 4; k++) {
        int new_x = i + x[k], new_y = j + y[k];

        if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && !visited[new_x][new_y]) {
            if (blindCheck(picture[i][j], picture[new_x][new_y])) blindDfs(new_x, new_y, n);
        }
    }
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    picture.assign(n, vector<char> (n, ' '));
    visited.assign(n, vector<bool> (n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> picture[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) continue;
            dfs(i, j, n);
            normal_cnt++;
        }
    }

    visited.assign(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) continue;
            blindDfs(i, j, n);
            blind_cnt++;
        }
    }
    cout << normal_cnt << ' ' << blind_cnt;

}