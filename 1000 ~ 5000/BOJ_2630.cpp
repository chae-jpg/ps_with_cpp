#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

int blue_cnt = 0, white_cnt = 0;

void checkSquare(int n, pi l, const vector<vector<bool>>& arr) {
    bool cmp = arr[l.first][l.second];
    for (int i = l.first; i < l.first + n; i++) {
        for (int j = l.second; j < l.second + n; j++) {
            if (arr[i][j] != cmp) {
                checkSquare(n/2, l, arr);
                checkSquare(n/2, {l.first, l.second + n/2}, arr);
                checkSquare(n/2, {l.first + n/2, l.second}, arr);
                checkSquare(n/2, {l.first + n/2, l.second + n/2}, arr);
                return;
            }
        }
    }
    if (cmp) blue_cnt++;
    else white_cnt++;
    return;
}

int main() {
    int n, t;
    vector<vector<bool>> arr;
    cin >> n;
    arr.assign(n, vector<bool> (n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> t;
            arr[i][j] = t;
        }
    }
    checkSquare(n, {0, 0}, arr);
    cout << white_cnt << '\n' << blue_cnt;

}