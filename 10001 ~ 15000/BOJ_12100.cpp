//2048(Easy) - 골드 2

#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> board;

int max_val = 2;

void move(int dir) {
    vector<vector<bool>> merged(n, vector<bool> (n, false));
    if (dir == 0) {
//        cout<<"up"<<'\n';
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                //맨 윗줄부터 차례대로 탐색
                if (board[i][j]) {
                    int x = i, y = j;
                    while (x-1 >= 0 && !board[x-1][y]) {
                        board[x-1][y] = board[x][y];
                        board[x][y] = 0;
                        x -= 1;
                    }
                    if (x <= 0) continue;
                    if (board[x-1][y] == board[x][y] && !merged[x-1][y]) {
                        board[x-1][y] *= 2;
                        merged[x-1][y] = true;
                        board[x][y] = 0;
                    }
                }
            }
        }
    }
    //왼쪽으로 밀기
    else if (dir == 1) {
//        cout<<"left"<<'\n';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                //맨 부터 차례대로 탐색
                if (board[i][j]) {
                    int x = i, y = j;
                    while (y-1 >= 0 && !board[x][y-1]) {
                        board[x][y-1] = board[x][y];
                        board[x][y] = 0;
                        y -= 1;
                    }
                    if (y <= 0) continue;
                    if (board[x][y-1] == board[x][y] && !merged[x][y-1]) {
                        board[x][y-1] *= 2;
                        merged[x][y-1] = true;
                        board[x][y] = 0;
                    }
                }
            }
        }
    } //아래로 밀기
    else if (dir == 2) {
//        cout<<"down"<<'\n';
        for (int j = 0; j < n; j++) {
            for (int i = n-1; i >= 0; i--) {
                //맨 윗줄부터 차례대로 탐색
                if (board[i][j]) {
                    int x = i, y = j;
                    while (x+1 < n && !board[x+1][y]) {
                        board[x+1][y] = board[x][y];
                        board[x][y] = 0;
                        x += 1;
                    }
                    if (x >= n-1) continue;
                    if (board[x+1][y] == board[x][y] && !merged[x+1][y]) {
                        board[x+1][y] *= 2;
                        merged[x+1][y] = true;
                        board[x][y] = 0;
                    }
                }
            }
        }
    } // 오른쪽으로 밀기
    else if (dir == 3) {
//        cout<<"right"<<'\n';
        for (int i = 0; i < n; i++) {
            for (int j = n-1; j >= 0; j--) {
                //맨 윗줄부터 차례대로 탐색
                if (board[i][j]) {
                    int x = i, y = j;
                    while (y+1 < n && !board[x][y+1]) {
                        board[x][y+1] = board[x][y];
                        board[x][y] = 0;
                        y += 1;
                    }
                    if (y >= n-1) continue;
                    if (board[x][y+1] == board[x][y] && !merged[x][y+1]) {
                        board[x][y+1] *= 2;
                        merged[x][y+1] = true;
                        board[x][y] = 0;
                    }
                }
            }
        }
    }

//    for (int i= 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << board[i][j] << ' ';
//        }
//        cout << '\n';
//    }

}

void backtrack(int cnt) {
    if (cnt == 6) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                max_val = max(board[i][j], max_val);
            }
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        vector<vector<int>> temp = board;
        //board를 움직임
//        cout << "cnt" << ' ' << cnt << '\n';
        move(i);
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                max_val = max(board[k][j], max_val);
            }
        }
        backtrack(cnt+1);
        //temp에 저장된 값으로 board 원복
        board = temp;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    board.assign(n, vector<int> (n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    backtrack(1);

    cout << max_val;
}