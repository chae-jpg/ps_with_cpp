//회전초밥 - 골드 4

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d, k, c, answer = 0;
    vector<int> sushi;
    cin >> n >> d >> k >> c;
    vector<int> ate;
    sushi.assign(n, 0);
    ate.assign(d+1, 0);

    for (int i = 0; i < n; i++) {
        cin >> sushi[i];
    }

    //초기 세팅
    int l = 0, r = k-1, cnt = 0;
    for (int i = l; i <= r; i++) {
        if (!ate[sushi[i]]) {
            cnt++;
        }
        ate[sushi[i]]++;
    }
    if (!ate[c]) cnt++;
    answer = max(answer, cnt);
    if (!ate[c]) cnt--;

    //r : 끝까지
    while (r < n-1) {
        l++; r++;
        ate[sushi[l-1]]--;
        //전 접시가 이번에 없으면 -> 카운트 감소.
        if (!ate[sushi[l-1]]) cnt--;
        //새 접시가 전에 없었으면 -> 카운트 증가.
        if (!ate[sushi[r]]) cnt++;
        ate[sushi[r]]++;
        if (!ate[c]) cnt++;
        answer = max(answer, cnt);
        //원상복구
        if (!ate[c]) cnt--;
    }
    r = 0, l++;
    //l : 끝까지
    while (l < n) {
        ate[sushi[l-1]]--;
        //전 접시가 이번에 없으면 -> 카운트 감소.
        if (!ate[sushi[l-1]]) cnt--;
        //새 접시가 전에 없었으면 -> 카운트 증가.
        if (!ate[sushi[r]]) cnt++;
        ate[sushi[r]]++;
        if (!ate[c]) cnt++;
        answer = max(answer, cnt);
        //원상복구
        if (!ate[c]) cnt--;
        l++; r++;
    }
    cout << answer;
}