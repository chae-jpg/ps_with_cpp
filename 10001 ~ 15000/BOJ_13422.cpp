#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, n, m, k;
    vector<int> arr;
    cin >> t;

    while (t--) {
        cin >> n >> m >> k;
        arr.assign(n, 0);        

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int right, sum, cnt = 0;
        for (int i = 0; i < n - (m - 1); i++) {
            right = i + m - 1;
            sum = 0;
            for (int j = i; j <= right; j++) {
                sum += arr[j];
            }
            if (sum <= k) cnt++;
        }
        for (int i = n-(m-1); i < n; i++) {
            right = m - i-1;
            for (int j = i; i < n; j++) {
                sum += arr[j];
            }
            for (int j = 0; j <= right; j++) {
                sum += arr[j];
            }
            if (sum <= k) cnt++;
        }


        cout << cnt << '\n';


    }


}