//카트라이더: 드리프트 - 브론즈 2

#include <bits/stdc++.h>

using namespace std;

typedef pair<string, string> ps;

int main() {
    int score[8] = {10, 8, 6, 5, 4,3, 2, 1};
    vector<ps> v;
    int r = 0, b= 0;
    for (int i = 0; i < 8; i++) {
        string a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < 8; i++) {
        if (v[i].second == "R") r+=score[i];
        else b+=score[i];
    }

    if (r>b) cout << "Red";
    else cout << "Blue";

}