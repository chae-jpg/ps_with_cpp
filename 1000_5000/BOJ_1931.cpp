#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

int main() {
    int n, cnt = 0;
    vector<pi> arr;
    cin >> n;
    arr.assign(n, {0, 0});

    for (int i = 0; i < n; i++) {
        cin >> arr[i].second >> arr[i].first;
    }

    sort(arr.begin(), arr.end());

    int finish_conference = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].second < finish_conference) {
            continue;
        }
        finish_conference = arr[i].first;
        cnt++;
    }

    cout << cnt;
}