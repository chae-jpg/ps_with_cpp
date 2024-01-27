//Dance Dance Revolution - 골드 3

#include <bits/stdc++.h>

using namespace std;

int x = 0, y = 0;
vector<int> coor;

int calcScore(int a, int b) {
    //같은 칸
    if (a == b) return 1;
    //0에서 이동
    if (!a || !b) return 2;
    //0 없으면서 인접
    if (abs(a-b) == 1 || abs(a-b) == 3) return 3;
    //반대편
    if (abs(a-b) == 2) return 4;
}

int solve() {
    int force = 0;

    for (int i = 0; i < coor.size(); i++) {
        int cur = coor[i];
        int x_s = calcScore(x, cur), y_s = calcScore(y, cur);

        if (x_s < y_s) x = cur;
        else if (y_s < x_s) y = cur;
        else if (i != coor.size() - 1){
            //다음 좌표에서 x를 누르라고 시키고 있으면 : x는 변동 없음. y만 이동시키기.
            if (x == coor[i+1]) y = cur;
            else x = cur;
        }
        force += min(x_s, y_s);
    }

    return force;
}

int main() {
    int a;
    while (cin >> a && a) {
        coor.push_back(a);
    }

    cout << solve();

}