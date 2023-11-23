#include <iostream>

using namespace std;

int main() {
    string str, target;
    int cnt = 0;
    getline(cin, str); getline(cin, target);

    if (str.length() < target.length()) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i <= str.length() - target.length(); i++) {
        if (i > str.length() - target.length()) break;
        string check = "";
        int j = i;
        for (; j < i + target.length(); j++) {
            check += str[j];
        }
        if (check == target) {
            cnt++;
            i = j-1;
        }
    }

    cout << cnt;

}