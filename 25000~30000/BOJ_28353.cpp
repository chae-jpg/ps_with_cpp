#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k, cnt = 0;
    vector<int> weight;

    cin >> n >> k;
    weight.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    sort(weight.begin(), weight.end());

    int l = 0, r = n-1;


    while (l < r && n > 0) {
        if (weight[l] + weight[r] <= k) {
            n--; l++; r--; cnt++;
        } else {
            r--;
        }
    }

    cout << cnt;

}