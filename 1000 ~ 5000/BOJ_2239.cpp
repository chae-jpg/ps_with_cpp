//스도쿠 - 골드 4

//스도쿠 - 골드 4

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board(9, vector<int>(9));

bool checkValue(int n, int x, int y) {
    //가로, 세로
    for (int i = 0; i < 9; i++) {
        if (board[x][i] == n) return false;
        if (board[i][y] == n) return false;
    }

    //정사각형
    int s_x, s_y;
    if (x < 3) s_x = 0;
    else if (x < 6) s_x = 3;
    else s_x = 6;

    if (y < 3) s_y = 0;
    else if (y < 6) s_y = 3;
    else s_y = 6;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[s_x+i][s_y+j] == n) return false;
        }
    }
    return true;
}

bool checkBoard(int x, int y) {
    if (x == 8 && y == 9) return true;

    if (y == 9) {
        x++;
        y = 0;
    }

    if (board[x][y]) return checkBoard(x, y+1);

    for (int i = 1; i <= 9; i++) {
        if(checkValue(i, x, y)) {
            board[x][y] = i;
            if (checkBoard(x, y+1)) return true;
        }
        board[x][y] = 0;
    }
    return false;

}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char t;
            cin >> t;
            board[i][j] = t-'0';
        }
    }

    if (checkBoard(0, 0)) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j];
            }
            cout << '\n';
        }
    }
}