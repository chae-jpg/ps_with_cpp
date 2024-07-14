#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    int k, l;
    vector<int> arr, sum;
    cin >> n >> m;
    arr.assign(n, 0);
    sum.assign(n+1, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum[i+1] = sum[i] + arr[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> k >> l;
        cout << sum[l] - sum[k - 1] << '\n';
    }

}