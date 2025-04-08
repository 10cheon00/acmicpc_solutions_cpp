/*
모든 선수들이 한번씩 서로 경기를 함
금화를 받는 규칙은 이긴 경기 수 + 줄에서 자기보다 앞에 있는데 자기가 이긴 선수 수
이긴 경기 수가 많은 사람이 최대한 앞으로 오도록 정렬해야 순서에 의해 주는 금화 수를 줄일 수 있음
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, P, M;
    cin >> N;
    vector<pair<int, int> > mans; // <힘, 마력>
    vector<pair<int, int> > list; // <이긴 사람 수(음수), 이긴 사람의 집합>
    for (int i = 0; i < N; i++) {
        cin >> P >> M;
        mans.emplace_back(P, M);
        list.emplace_back(0, i + 1);
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (mans[i].first + mans[i].second * mans[j].first >
                mans[j].first + mans[j].second * mans[i].first) {
                list[i].first--;
            } else {
                list[j].first--;
            }
        }
    }
    sort(list.begin(), list.end());
    for (int i = 0; i < N; i++) {
        cout << list[i].second << '\n';
    }
}
