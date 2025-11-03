// 화장실의 규칙 - 골드 4
// 풀이 소요시간 : 1시간 10분

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

/*
필요한 작업

1. 기존 줄 1개를 M개의 줄로 분할.
2. M개의 줄의 선두 중 주어진 조건에 따라 한 명의 선두를 선택.
    1. 근무 일수 D가 높은 사람
    2. 화장실이 급한 정도 H가 높은 사람
    3. 줄의 번호가 낮은 사람

아이디어

- 과정을 그대로 시뮬레이션 하기 위해 queue를 사용하는 것이 최적 (queue의 작동은 줄 서기와 유사하므로)
- 데카의 위치를 기억하고, queue m개를 만들어 사원들을 집어넣은 후, 과정을 시뮬레이션하다 데카가 나오면 멈추고 해당 횟수를 리턴하기.
- 선두의 사원들 비교에 어떤 방법이 효율적? 
    - 1. 배열에 넣고 소트 (nlogn)
    - 2. pq에 넣고 가장 앞 원소 꺼내기 (logn)
*/

struct Person{
    int line;
    int order;
    int m;
    int k;
};

struct Compare {
    bool operator() (const Person a, const Person b) {
        if (a.m != b.m) {
            return a.m < b.m;
        }
        if (a.k != b.k) {
            return a.k < b.k;
        }
        return a.line > b.line;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, k;
    int line, order, d, h;
    cin >> n >> m >> k;
    pi deka = {k%m, k/m};

    // 1. queue에 직원 집어넣기
    vector<queue<Person>> v (m, queue<Person> ());

    for (int i = 0; i < n; i++) {
        line = i % m;
        order = i / m;
        cin >> d >> h;

        Person p = {line, order, d, h};
        v[line].push(p);
    }

    // 2. 과정 시뮬레이션 (앞 원소들 꺼내서 D -> H -> 번호 비교)

    int cnt = 0;
    priority_queue<Person, vector<Person>, Compare> pq;

    // 1. pq 초기화
    for (auto &q: v) {
        if (!q.empty()) {
            pq.push(q.front());
            q.pop();
        }
    }

    while (true) {
        // 2. 뽑힌 선두 중 가장 높은 우선순위인 사람 꺼내기
        Person next = pq.top();
        pq.pop();

        // 3. 데카면 종료, 아니면 계속
        if (make_pair(next.line, next.order) == deka) break;

        // (4). 방금 사람 빼온 줄에서 새로운 사람 추가
        if (!v[next.line].empty()) {
            pq.push(v[next.line].front());
            v[next.line].pop();
        }
        cnt++;
    }
    cout << cnt;
}