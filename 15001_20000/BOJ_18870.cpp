#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n,cnt = 0;
    vector<int> arr;
    map<int, int> m;

    cin >> n;
    arr.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        m.insert({arr[i], 0});
    }

    for (auto iter = m.begin(); iter != m.end(); iter++) {
        iter->second = cnt++;
    }

    for (int i : arr) {
        cout << m[i] << ' ';
    }
}