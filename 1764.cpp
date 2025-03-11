#include <iostream>
#include <string>
#include <set>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    char name[21];
    cin >> N >> M;
    set<string> nnn;
    priority_queue<string, vector<string>, greater<string>> list;

    // 집합에 이름 추가
    for (int i=0; i<N; i++) {
        cin >> name;
        nnn.emplace(name);
    }

    // 집합에 이름이 있는지 검사 후 있으면 다른 자료구조에 이름 추가
    for (int i=0; i<M; i++) {`
        cin >> name;
        if (nnn.find(name) != nnn.end()) {
            list.emplace(name);
        }
    }
    cout << list.size() << '\n';
    while (!list.empty()) {
        cout << list.top() << '\n';
        list.pop();
    }
    // 이름이 중복되어서 추가했었던 자료구조를 정렬 후 출력

}
