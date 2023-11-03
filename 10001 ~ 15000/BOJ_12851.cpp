//숨바꼭질 2 - 골드 4

#include <iostream>
#include <queue>

using namespace std;

#define MAX_N 100000

bool is_used[MAX_N + 1] = {false}, same_found = false;

int find_time = 0, cnt = 0, time_saved;

void bfs(int n, int k) {
    queue<int> q;
    int top;

    if (n == k) {
        cnt = 1;
        find_time = 0;
        return;
    }

    q.push(n);
    is_used[n] = true;

    while(!q.empty()) {
        find_time++;
        int len = q.size();
        for (int i = 0; i < len; i++) {
            top = q.front();
            q.pop();
            if (top-1 == k) cnt++;
            if (top+1 == k) cnt++;
            if (top*2 == k) cnt++;
            if (top -1 >= 0 && !is_used[top-1]) {
                q.push(top-1);
                is_used[top-1] = true;
            }
            if (top +1 <= MAX_N && !is_used[top+1]) {
                q.push(top+1);
                is_used[top+1] = true;
            }
            if (top * 2 <= MAX_N && !is_used[top*2]){
                q.push(top*2);
                is_used[top*2] = true;
            }
        }
        if (cnt) {
            return;
        }
    }

}

int main() {
    int n, k;
    cin >> n >> k;
    bfs(n, k);
    cout << find_time << '\n' << cnt;


}