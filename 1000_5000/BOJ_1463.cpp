#include <iostream>

using namespace std;

const int MAX_N = 10e6+1;
int arr[MAX_N * 3] = {0};

void makeArr() {
    for (int i = 1; i <= MAX_N - 2; i++) {
        if(arr[i+1] == 0 || (arr[i+1] != 0 && arr[i+1] > arr[i] + 1)) arr[i+1] = arr[i] + 1;
        if(arr[i*2] == 0 || (arr[i*2] != 0 && arr[i*2] > arr[i] + 1)) arr[i*2] = arr[i] + 1;
        if(arr[i*3] == 0 || (arr[i*3] != 0 && arr[i*3] > arr[i] + 1)) arr[i*3] = arr[i] + 1;
    }



}

int main() {
    makeArr();
    int n;
    cin >> n;
    cout << arr[n];
}