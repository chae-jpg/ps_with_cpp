#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, l = 1;
    char c;
    vector<vector<int>> arr;
    cin >> n >> m;
    arr.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            arr[i][j] = c-'0';
        }
    }

    for (int i = 0; i < m-1; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = n-1; k >= j; k--) {
                if (arr[j][i] == arr[k][i]) {
                    if ((k - j + 1) > l) {
                        int t = k - j;
                        if (i+t < m && j+t < n && arr[j][i+t] == arr[j][i] && (arr[j+t][i+t] == arr[j][i])) {
                            l = t + 1;
                        }
                    }
                }
            }
        }
    }

    cout << l * l;
}