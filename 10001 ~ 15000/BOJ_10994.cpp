#include <iostream>

using namespace std;

void printStar(int n) {
    if (n == 1) {
        cout << '*';
        return;
    };
    for (int i = 0; i < (n-1) * 5; i++) {
        cout << '*';
    }
    cout << '\n';

    cout << '*';
    for (int i = 0; i < (n-1) * 5 - 2; i++) {
        cout << ' ';
    }
    cout << "*\n";

    cout << "* ";
    printStar(n-1);
    cout << " *\n";
    cout << '*';
    for (int i = 0; i < (n-1) * 5 - 2; i++) {
        cout << ' ';
    }
    cout << "*\n";

    for (int i = 0; i < (n-1) * 5; i++) {
        cout << '*';
    }
    cout << '\n';
}

int main() {
    int n;
    cin >> n;

    printStar(n);

}