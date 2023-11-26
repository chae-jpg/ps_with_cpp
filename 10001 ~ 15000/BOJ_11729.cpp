// 하노이 탑 이동 순서 - 골드 5

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

int cnt = 0;
vector<pi> answer;

void moveDisc(int n, int from, int tmp, int to) {
    cnt++;
    if (n == 1) {
        answer.push_back({from, to});
        return;
    }
    moveDisc(n-1, from, to, tmp);
    answer.push_back({from, to});
    moveDisc(n-1, tmp, from, to);
}

int main() {
    int n;
    cin >> n;
    moveDisc(n, 1, 2, 3);
    cout << cnt << '\n';

    for (pi a : answer) {
        cout << a.first << ' ' << a.second << '\n';
    }
}