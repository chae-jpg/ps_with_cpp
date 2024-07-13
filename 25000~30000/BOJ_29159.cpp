// 케이크 두 개 - 실버 3

#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> pi;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

pi round(pi a) {
    long long div = gcd(a.first, a.second);
    return {a.first / div, a.second / div};
}

pi sub(pi a, pi b) {
    if (a.second == b.second) return {b.first - a.first, b.second};
    long long div = gcd(a.second, b.second);
    long long lcm = a.second * b.second * div;
    a.first *= (lcm / a.second); a.second *= (lcm / a.second);
    b.first *= (lcm / b.second); b.second *= (lcm / b.second);
    return {b.first - a.first , lcm};
}
pi sum(pi a, pi b) {
    long long div = gcd(a.second, b.second);
    long long lcm = a.second * b.second * div;
    a.first *= (lcm / a.second); a.second *= (lcm / a.second);
    b.first *= (lcm / b.second); b.second *= (lcm / b.second);
    return {b.first + a.first , lcm};
}

int main() {
    pi coor_a_1, coor_a_2, coor_b_1, coor_b_2;
    int x = 0, y = 0;
    for (int j = 0; j < 4; j++) {
        int a, b; cin >> a >> b;
        x += a, y += b;
    }
    long long div = gcd(x, 4);
    coor_a_1 = {x/div, 4/div};
    div = gcd(y, 4);
    coor_a_2 = {y/div, 4/div};

    x = 0, y = 0;
    for (int j = 0; j < 4; j++) {
        int a, b; cin >> a >> b;
        x += a, y += b;
    }
    div = gcd(x, 4);
    coor_b_1 = {x/div, 4/div};
    div = gcd(y, 4);
    coor_b_2 = {y/div, 4/div};

    // 기울기 구하기
    pi calc_1 = sub(coor_a_2, coor_b_2);
    pi calc_2 = sub(coor_a_1, coor_b_1);
    pi slope = {calc_2.second * calc_1.first, calc_2.first * calc_1.second};
    slope = round(slope);

    calc_1 = {slope.first * -(coor_a_1.first), slope.second * coor_a_1.second};
    calc_2 = sum(calc_1, coor_a_2);
    calc_2 = round(calc_2);

    if (slope.first < 0 || slope.second < 0) {
        slope.first = - abs(slope.first);
        slope.second = abs(slope.second);
    }
    if (calc_2.first < 0 || calc_2.second < 0) {
        calc_2.first = - abs(calc_2.first);
        calc_2.second = abs(calc_2.second);
    }

    cout << slope.first;
    if (slope.second != 1) cout << '/' << slope.second;
    cout << ' ';
    cout << calc_2.first;
    if (calc_2.second != 1) cout << '/' << calc_2.second;
    cout << ' ';

}