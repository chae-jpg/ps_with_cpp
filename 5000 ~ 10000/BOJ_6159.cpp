#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, s, cnt = 0;
    vector<int> cow;
    cin >> n >> s;
    cow.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> cow[i];
    }
    sort(cow.begin(), cow.end());

    int right = n-1;


    //cnt를 일일히 반복해주면서 증가시켜주기 때문에 비효율.
    // while (right != 0) {
    //     if (left != right && cow[left] + cow[right] <= s) {
    //         left++;
    //         cnt++;
    //     } else {
    //         right--;
    //         left = 0;
    //     }
    // }
    //1 2 3 5
    //1 2 3 4 5 6 7 8 9 10
    for (int i = 0; i < n-1; i++) {
        //while (cow[i] + cow[right] > s && right > i) right--; //left + right한 값이 s보다 크고, right가 i보다 큰 동안 반복 -> left+right==s, right==i 가능성 존재.
        right = upper_bound(cow.begin() + i, cow.end(), s - cow[i]) - cow.begin();  //아니면 s에서 i를 뺀 것보다 큰 수가 있는 인덱스로 이동하기.   
        //lower_bound 안 되는 이유 : 1 - 5는 right - i = 3, 문제 x, but 2 - 3에서 6-2 = 4이므로 5로 이동 -> right - i = 2이므로 잘못된 결과.
        //따라서 s - cow[i]가 같은 경우가 있더라도 한 칸 뒤로 빼줘야(upper_bound) 함, 그래야 인덱스를 다시 또 앞으로 땡겨서(right--), 모든 경우에 적용 가능.
        right--;
        if (i >= right) break;
        cnt += right - i;

    }

    cout << cnt;
}
