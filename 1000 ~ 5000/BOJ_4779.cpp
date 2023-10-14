// 칸토어 집합 - 실버 3

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void makeCantor(string& str, int l, int r) {
    if (l >= r) return;
    int len = (r - l) / 3 + 1;
    fill(str.begin() + l + len, str.begin() + r - len + 1, ' ');
    makeCantor(str, l, l+len-1);
    makeCantor(str, r-len+1, r);
}

int main() {
    int n;
    while (cin >> n) {
        string answer (pow(3, n), '-');
        makeCantor(answer, 0, pow(3, n) - 1);
        cout << answer << '\n';
    }
}

