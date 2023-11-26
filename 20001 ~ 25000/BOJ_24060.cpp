#include <iostream>
#include <vector>

using namespace std;

int cnt = 0, k;

void merge(vector<int>& arr, int p, int q, int r) {
    int i = p, j = q + 1;
    vector<int> temp;
    while (i <= q && j <= r) {
        if (arr[i] < arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }
    while (i <= q) {
        temp.push_back(arr[i++]);
    }
    while (j <= r) {
        temp.push_back(arr[j++]);
    }
    i = p;
    for (int t : temp) {
        arr[i++] = t;
        cnt++;
        if (cnt == k) {
            cout << t;
            return;
        }
    }
}

void mergeSort(vector<int>& arr, int p, int r) {
    if (p >= r) return;

    int q = (p + r) / 2;
    mergeSort(arr, p, q);
    mergeSort(arr, q+1, r);
    merge(arr, p, q, r);
}


int main() {
    ios_base ::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    int a;
    vector<int> arr;
    cin >> a >> k;
    arr.assign(a, 0);

    for (int i = 0; i < a; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, a - 1);

    if (cnt < k) {
        cout << -1;
    }
}