//Azber is playing at Biou's house - 골드 1

#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, bool> p;

vector<int> score;
vector<bool> visited;

set<int> limit;

int n;

int dfs(int i, long long sum, bool azber, long long min_sum, long long max_sum) {
    visited[i] = true;
    if (i == 1) {
        if (azber) {
            if (max_sum == -1e14) return sum;
            return max(sum, max_sum);
        }
        else {
            if (min_sum == 1e14) return sum;
            return min(sum, min_sum); }
    }
    int next_idx = 0, next_score;
    if (azber) {
        next_score = 1e9;
        if (i%2 != 0 && !visited[i-1]) {
            if (score[i-1] < next_score) {
                next_idx = i-1;
                next_score = score[i-1];
            }
        }
        if (!visited[i/2] && score[i/2] < next_score) {
            next_idx = i/2;
            next_score = score[next_idx];
        }
        if (limit.find(i) == limit.end() && !visited[i+1]) {
            if (score[i+1] < next_score) {
                next_idx = i+1;
                next_score = score[next_idx];
            }
        }
        if (next_score == 1e9) {
            return min(sum, min_sum);
        }
    }
    else {
        next_score = -1e9;
        if (i%2 == 0 && !visited[i-1]) {
            if (score[i-1] > next_score) {
                next_idx = i-1;
                next_score = score[i-1];
            }
        }
        if (score[i/2] > next_score && !visited[i/2]) {
            next_idx = i/2;
            next_score = score[next_idx];
        }
        if (limit.find(i) == limit.end() && !visited[i+1]) {
            if (score[i+1] > next_score) {
                next_idx = i+1;
                next_score = score[next_idx];
            }
        }
        if (next_score == 1e9) {
            return max(sum, max_sum);
        }
    }
    if (azber) min_sum = min(sum, min_sum);
    else max_sum = max(max_sum, sum);
    sum += next_score;
    if (azber) min_sum = min(sum, min_sum);
    else max_sum = max(max_sum, sum);
    return dfs(next_idx, sum, !azber, min_sum, max_sum);
}

int main() {
    limit.insert(3); limit.insert(7); limit.insert(15); limit.insert(31); limit.insert(63); limit.insert(127); limit.insert(255); limit.insert(511); limit.insert(1023); limit.insert(2043);
    cin >> n;
    n = pow(2, n) - 1;
    score.assign(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> score[i];
    }
    cout <<score[1] << ' ';
    for (int i =2; i <= n; i++) {
        visited.assign(n+1, false);
        cout << dfs(i, score[i], true,1e14, -1e14) << ' ';
    }
}