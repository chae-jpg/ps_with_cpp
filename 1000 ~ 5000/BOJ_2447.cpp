//별 찍기 - 10 - 골드 5

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

void makePattern(vector<vector<char>>& arr, pi l, pi r) {
    int len = (r.first - l.first + 1) / 3;
    if (!len) return;

    for (int i = l.first + len; i < r.first -len + 1; i++) {
        for (int j = l.second + len; j < r.second -len + 1; j++) {
            arr[i][j] = ' ';
        }
    }

    makePattern(arr, l, {l.first + len - 1, l.second + len - 1});
    makePattern(arr, {l.first + len, l.second}, {r.first - len, l.second + len - 1});
    makePattern(arr, {r.first - len +1, l.second}, {r.first, l.second + len - 1});

    makePattern(arr, {l.first, l.second + len}, {l.first + len - 1, r.second - len});
    makePattern(arr, {r.first - len +1, l.second + len}, {r.first, r.second - len});

    makePattern(arr, {l.first, r.second - len + 1}, {l.first + len - 1, r.second});
    makePattern(arr, {l.first + len, r.second-len+1}, {r.first - len, r.second});
    makePattern(arr, {r.first - len + 1, r.second - len + 1}, r);

}

int main() {
    int n;
    vector<vector<char>> arr;
    cin >> n;
    arr.assign(n, vector<char> (n, '*'));

    makePattern(arr, {0, 0}, {n-1, n-1});

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }
}