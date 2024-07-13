//드래곤 커브 - 골드 3

#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 100;
//우, 상, 좌, 하
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int cntSquare(vector<vector<bool>>& plane) {
    int ans = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (plane[i][j] && plane[i+1][j] && plane[i][j+1] && plane[i+1][j+1]) {
                ans++;
            }
        }
    }
    return ans;
}

void drawDragonCurve(vector<vector<bool>>& plane, int x, int y, int d, int g) {
    vector<int> direct;
    plane[y][x] = plane[y + dy[d]][x + dx[d]] = true;
    x += dx[d]; y += dy[d];
    direct.push_back(d);

    while(g--) {
        int size_d = direct.size();
        for (int j = size_d - 1; j >= 0; j--) {
            int next_d = (direct[j] + 1) % 4;
            x += dx[next_d]; y += dy[next_d];
            plane[y][x] = true;
            direct.push_back(next_d);
    }

}

int main() {
    int n, x, y, d, g;
    vector<vector<bool>> plane(SIZE + 1, vector<bool> (SIZE+1, false));

    cin >> n;

    while (n--) {
        cin >> x >> y >> d >> g;
        drawDragonCurve(plane, x, y, d, g);
    }

    cout << cntSquare(plane);


}