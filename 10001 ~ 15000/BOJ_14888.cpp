//연산자 끼워넣기 - 실버 1

#include <iostream>
#include <vector>

using namespace std;


int n, max_num = -1e9 - 1, min_num = 1e9 + 1;
vector<int> num;
vector<int> oper(4, 0);

void backtrack(int result, int cnt) {
    if (cnt == n-1) {
        min_num = min(result, min_num);
        max_num = max(result, max_num);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (oper[i]) {
            oper[i]--;
            switch(i) {
                case 0 :
                    backtrack(result + num[cnt+1], cnt+1);
                    break;
                case 1 :
                    backtrack(result - num[cnt+1], cnt+1);
                    break;
                case 2 :
                    backtrack(result * num[cnt+1], cnt+1);
                    break;
                case 3 :
                    backtrack(result / num[cnt+1], cnt+1);
                    break;
            }
            oper[i]++;
        }
    }

}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    num.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> oper[i];
    }

    backtrack(num[0], 0);
    cout << max_num << '\n' << min_num;


}