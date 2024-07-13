//별 찍기 - 4 - 브론즈 3

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) cout << ' ';
        for (int j = 0; j < n- i; j++) cout << '*';
        cout << '\n';
    }
}