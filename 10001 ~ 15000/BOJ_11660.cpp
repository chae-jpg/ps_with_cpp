#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    int x1, x2, y1, y2;
    vector<vector<int>> arr, sum;
    cin >> n >> m;

    arr.assign(n, vector<int> (n, 0));
    sum.assign(n+1, vector<int> (n+1, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] + arr[i][j] - sum[i][j];
        }
    }

    for (int i = 0; i < m; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1] << '\n';
    }
}