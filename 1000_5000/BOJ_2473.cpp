#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int n, int arr[]) {
	long long max_sol = -3 * 1e9;
	int max_l = 0, max_m = 1, max_r = n - 1;

	for (int i = 0; i < n - 2; i++) {
		int l = i + 1, r = n - 1;
		while (l < r) {
            long long sum = arr[i];
			sum += arr[l] + arr[r];

			if (abs(sum) < abs(max_sol)) {
				max_l = l; max_r = r; max_m = i;
				max_sol = sum;
			}
			if (sum < 0) l++;
			else r--;
		}
	}
    vector<int> ans;
    ans.push_back(arr[max_l]);
    ans.push_back(arr[max_m]);
    ans.push_back(arr[max_r]);
    sort(ans.begin(), ans.end());

    for (int n : ans) {
        cout << n << ' ';
    }
}

int main() {
	int n, arr[5000];
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
    sort(arr, arr+n);
	solve(n, arr);




}