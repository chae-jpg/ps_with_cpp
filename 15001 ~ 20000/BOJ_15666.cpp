// N과 M (12) - 실버 2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answer;

void backtrack(int m, vector<int>& arr, int cnt, int n) {
    if (cnt == m) {
        for (int a : answer) {
            cout << a << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = n; i < arr.size(); i++) {
        answer.push_back(arr[i]);
        backtrack(m, arr, cnt+1, i);
        answer.pop_back();
    }
}

int main() {
    int n, m;
    vector<int> arr;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int t;
        bool check = false;
        cin >> t;
        for (int j = 0; j < i; j++) {
            if (arr[j] == t) {
                check = true;
                break;
            }
        }
        if (!check) {
            arr.push_back(t);
        }
    }
    sort(arr.begin(), arr.end());
    backtrack(m, arr, 0, 0);
}