// N-Queen - 골드 4

#include <iostream>
#include <vector>

using namespace std;

int place_cnt = 0;
vector<bool> col, diag1, diag2;


void search(int s_cnt , int n) {
    if (s_cnt == n) {
        place_cnt++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (col[i] || diag1[s_cnt+i] || diag2[i-s_cnt+n-1]) continue;
        col[i] = true;
        diag1[s_cnt + i] = true;
        diag2[i - s_cnt + n - 1] = true;
        search(s_cnt + 1, n);
        col[i] = false;
        diag1[s_cnt + i] = false;
        diag2[i - s_cnt + n - 1] = false;
    }

}

int main() {
    int n;
    cin >> n;
    col.assign(n, false);
    diag1.assign(n, false);
    diag2.assign(n, false);


    search(0, n);

    cout << place_cnt;
}