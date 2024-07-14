#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    map<char, int> val;
    vector<pair<int, char>> pq;

    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        arr[i] = t;
        int l = t.length();
        for (int j = 0; j < l; j++) {
            int expo = l-j-1;
            val[t[j]] += (int)pow(10, expo);
        }
    }

    for (auto iter = val.begin(); iter != val.end(); iter++) {
        pq.push_back({iter->second, iter->first});
    }

    sort(pq.begin(), pq.end());
    int num = 9;
    while (!pq.empty()) {
        pair<int, char> top;
        top = pq[pq.size()-1];
        val[top.second] = num--;
        pq.pop_back();
    }


    int sum = 0;
    for (int i = 0; i < n; i++) {
        string t;
        for (char c : arr[i]) {
            t += val[c] + '0';
        }
        sum += stoi(t);
    }
    cout << sum;
}