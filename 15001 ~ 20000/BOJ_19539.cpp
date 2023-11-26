#include <iostream>
#include <vector>

using namespace std;

string checkTree(int sum, int one_cnt, int remainder_one, int remainder_two) {
    if (sum%3) {
        return "NO";
    }
    if (one_cnt != 0 && (3 - one_cnt%3) > remainder_one + remainder_two * 2) {
        return "NO";
    }
    return "YES";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, one_cnt = 0, sum = 0, remainder_one = 0, remainder_two = 0, t;
    cin >> n;

    while(n--) {
        cin >> t;
        if (t == 1) {
            one_cnt++;
        } else if (t%3 == 1) {
            remainder_one++;
        } else if (t%3 == 2) {
            remainder_two++;
        }
        sum+=t;
    }
    cout << checkTree(sum, one_cnt, remainder_one, remainder_two);

}