#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    bool flag = false;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = n-1; j >= i+1; j--) {
            if (arr[j-1][1] > arr[j][1]) {
                swap(arr[j-1], arr[j]);
            } else if (arr[j-1][1] == arr[j][1] && arr[j-1][0] > arr[j][0]) {
                flag = true;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    if (flag) cout << "Not Stable";
    else cout << "Stable";

    flag = false;

}