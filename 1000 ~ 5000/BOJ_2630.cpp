#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

int cnt = 0;

void divideSquare (vector<vector<bool>>& arr, pi left_top, pi right_down) {
    int h_mid = (left_top.first + right_down.first)/2, w_mid = (left_top.second + right_down.second)/2;
    bool check, flag = true;
    //왼쪽 위
    check = arr[left_top.first][left_top.second];
    for (int i = left_top.first; i < h_mid; i++) {
        for (int j = left_top.second; j < w_mid; j++) {
            if (arr[i][j] != check) {
                flag = false;
                divideSquare(arr, left_top, {h_mid, w_mid});
                break;
            }
            if (!flag) {
                break;
            }
        }
    }
    if (flag) {
        cnt++;
    }
    flag = true;

    //오른쪽 위
    check = arr[left_top.first][w_mid];
    for (int i = left_top.first; i < h_mid; i++) {
        for (int j = w_mid; j < right_down.second; j++) {
            if (arr[i][j] != check) {
                flag = false;
                divideSquare(arr, {left_top.first, w_mid}, {h_mid, right_down.second});
                break;
            }
            if (!flag) {
                break;
            }
        }
    }
    if (flag) {
        cnt++;
    }
    flag = true;

    //왼쪽 아래
    check = arr[h_mid][left_top.second];
    for (int i = h_mid; i < right_down.first; i++) {
        for (int j = left_top.second; j < w_mid; j++) {
            if (arr[i][j] != check) {
                flag = false;
                divideSquare(arr, {h_mid, left_top.second}, {right_down.first, w_mid});
                break;
            }
            if (!flag) {
                break;
            }
        }
    }
    if (flag) {
        cnt++;
    }
    flag = true;

    //오른쪽 아래
    check = arr[h_mid][w_mid];
    for (int i = h_mid; i < right_down.first; i++) {
        for (int j = w_mid; j < right_down.second; j++) {
            if (arr[i][j] != check) {
                flag = false;
                divideSquare(arr, {h_mid, w_mid}, right_down);
                break;
            }
            if (!flag) {
                break;
            }
        }
    }
    if (flag) {
        cnt++;
    }
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

    divideSquare(arr, {0, 0}, {n, n});

    cout << cnt;

}