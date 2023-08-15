#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void recur(int idx, string n, vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (n[idx] - '0' == arr[i]) {
            cout << arr[i];
            return recur(idx + 1, n, arr);

        }
        else if (n[idx] - '0' > arr[i]) {
            cout << arr[i];
            for (int j = 0; j < n.length() - idx -1; j++) {
                cout << arr[0];
            }
            return;
        }
    }

}

int main() {
    string n;
    int k;
    cin >> n >> k;
    vector<int> arr (k, 0);

    while (k--) {
        cin >> arr[k];
    }

    sort(arr.begin(), arr.end(), greater<>());

    recur(0, n, arr);

}



