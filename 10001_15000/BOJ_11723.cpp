#include <iostream>

using namespace std;



int main() {
    int m, x = 0;
    int total = 0b0;
    cin >> m;
    while (m--) {
        string s;
        cin >> s;

        if (s == "add") {
            cin >> x;
            total |= (1 << x);
        } else if (s == "remove") {
            cin >> x;
            total &= ~(1 << x);
        } else if (s == "check") {
            cin >> x;
            if ((total & (1 << x)) == 0) cout << 0 << '\n';
            else cout << 1 << '\n';
        } else if (s == "toggle") {
            cin >> x;
            if ((total & (1 << x)) == 0) total |= (1<<x);
            else total &= ~(1 << x);
        } else if (s == "all") {
            total = 2097150;
        } else {
            total = 0;
        }
    }




}
