#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student 
{
    int age;
    string name;
};

bool cmp(const Student& s1, const Student& s2) {
    return s1.age < s2.age;
}

int main() {
    vector<Student> stu;
    int n;
    cin >> n;
    stu.assign(n, {});

    for (int i = 0; i < n; i++) {
        cin >> stu[i].age >> stu[i].name;
    }

    sort(stu.begin(), stu.end(), cmp);

    for (int i = 0; i < n; i++) {
        cout << stu[i].age << " " << stu[i].name << '\n';
    }

}