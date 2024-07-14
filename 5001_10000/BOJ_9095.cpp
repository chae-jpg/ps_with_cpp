#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> arr(13, vector<int>(4, 0));

void makeArr() {
    arr[1][1] = 1;
    arr[2][2] = 1;
    arr[3][3] = 1;
    for (int i = 1; i <= 9; i++) {
        int sum = arr[i][1] + arr[i][2] + arr[i][3];
        arr[i+1][1] = sum;
        arr[i+2][2] = sum;
        arr[i+3][3] = sum;

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t, n;
    cin >> t;
    makeArr();
    
    while (t--) {
      cin >> n;
      cout << arr[n][1] + arr[n][2] + arr[n][3] <<'\n';
    }
}