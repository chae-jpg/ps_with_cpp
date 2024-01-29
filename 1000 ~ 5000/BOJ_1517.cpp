//버블 소트 - 플래티넘 5

#include <bits/stdc++.h>

using namespace std;

long long cnt = 0;

vector<long long> arr;
vector<long long> sorted;

void merge(int l, int mid, int r) {
    int i = l, j = mid+1, k = l;

    while (i <=mid && j <= r) {
        if (arr[i]<=arr[j]) {
            sorted[k++] = arr[i++];
        }
        else {
            cnt += (mid - i)+1;
            sorted[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        sorted[k++] = arr[i++];
    }
    while (j <= r) {
        sorted[k++] = arr[j++];
    }
    for (i = l; i<= r; i++) {
        arr[i] = sorted[i];
    }
}

void divide(int l, int r) {
    if (l < r) {
        int mid = (l+r)/2;
        divide(l, mid);
        divide(mid+1, r);
        merge(l, mid, r);
    }
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    arr.assign(n, 0);
    sorted.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    divide(0, n-1);
    cout << cnt;


}