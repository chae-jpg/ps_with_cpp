#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> answer;

void backtrack(int n, int m, int cnt, int front) {
    if (cnt == m) {
        for (int a : answer) {
            cout << a << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = front; i < n; i++) {
        answer[cnt] = arr[i];
        backtrack(n, m, cnt+1, i);
    }
}

int main() {
    int n, m;

    cin >> n >> m;

    arr.assign(n, 0);
    answer.assign(m, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    backtrack(n, m, 0, 0);

}