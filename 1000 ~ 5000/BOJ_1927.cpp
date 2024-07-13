//최소 힙 - 실버 2

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    priority_queue<int> pq;
    cin >> n;

    while (n--) {
        int t;
        cin >> t;

        if (t) {
            pq.push(-t);
        } else {
            if (!pq.empty()) {
                cout << -pq.top() << '\n';
                pq.pop();
            } else {
                cout << 0 << '\n';
            }
        }
    }




}