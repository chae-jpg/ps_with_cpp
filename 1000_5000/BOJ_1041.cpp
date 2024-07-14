#include <iostream>

using namespace std;

int main() {
    int n, number[6], min_one = 51, min_two = 100, min_three = 150, max = 0;

    cin >> n;
    for (int i = 0; i < 6; i++) {
        cin >> number[i];
        if (number[i] < min_one) min_one = number[i];
        if (number[i] > max) max = number[i];
    }

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (i + j == 5) continue;
            if (number[i] + number[j] < min_two) min_two = number[i] + number[j];
        }
    }

    int add = min(number[2], number[3]);
    if (add + number[0] + number[1] < min_three) min_three = add + number[0] + number[1];
    if (add + number[0] + number[4] < min_three) min_three = add + number[0] + number[4];
    if (add + number[5] + number[1] < min_three) min_three = add + number[1] + number[5];
    if (add + number[5] + number[4] < min_three) min_three = add + number[5] + number[4];

    if (n == 1) {
        int sum = 0;
        for (int n : number) {
            sum += n;
        }
        cout << sum - max;
    }
    else if (n == 2) {
        cout << min_three * 4 + min_two * 4;
    }
    else {
        unsigned long long sum = min_three * 4 + min_two * (8 * n - 12);
        unsigned long long sum_part = min_one * (5 * (long long)n * n - 16 * n + 12);    //형 변환 이렇게 숫자 바로 앞에 붙여야 적용됨!!
        cout << sum + sum_part;
    }



}