//두 용액 - 골드 5

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int a_l, a_r, min_char = 2*1e9;

void findMin(const vector<int>& arr) {
    int l = 0, r = arr.size() - 1;

    while (l < r) {
        int sum = arr[l] + arr[r];
        if (abs(min_char) > abs(sum)) {
            min_char = sum;
            a_l = arr[l];
            a_r = arr[r];
        }

        if (sum > 0) {
            r--;
        } else {
            l++;
        }
    }
}

int main() {
    int n;
    vector<int> arr;
    cin >> n;
    arr.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort (arr.begin(), arr.end());

    findMin(arr);

    cout << a_l << ' ' <<  a_r;

}