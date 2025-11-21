#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<string> v;
    v.assign(15, "");
    string t;
    for (int i = 0; i < 5; i++) {
        cin >> t;
        for (int j = 0; j < t.length(); j++) {
            v[j] += t[j];
        }
    }

    for (int i = 0; i < 15; i++) {
        cout << v[i];
    }
}
