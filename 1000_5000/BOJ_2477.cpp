// 참외밭 - 실버 2

#include <bits/stdc++.h>

using namespace std;

int k;
int a, b;

vector<int> v, d;
int main() {
    cin >> k;


    for (int i = 0; i < 6; i++) {
        cin >> a >> b;
        d.push_back(a);
        v.push_back(b);
    }



    int idx = -1;
    int max_len = -1;

    for (int i = 0; i < 6; i++) {
        if (max_len < v[i]) {
            max_len = v[i];
            idx = i;
        }
    }

    int next_idx = -1, next_len = -1;
    int l = (idx + 5) % 6, r = (idx + 1) % 6;

    next_idx = (v[l] > v[r]) ? l : r;
    next_len = v[next_idx];


    l = (idx + 3) % 6, r = (next_idx + 3) % 6;
    int small_l = v[l];
    int small_r = v[r];

    cout << (max_len * next_len - small_l * small_r) * k;

}