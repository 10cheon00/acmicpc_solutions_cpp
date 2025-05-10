/*
집합에서 3개의 수를 고르고, 그 수의 합이 집합에 있는지. 그런 세 수의 합의 최대는?
N=1000,
문제에서 3개의 수를 고르는게 서로 다른 3개의 수를 고르는게 아니라 했으니,
Nc3 = 1000*999*998/6 ~~ 1.6억이 아니라
N^3이므로 1000*999*998? 순서가 있으니까...
집합에서 3개의 수를 고르는게 꼭 작은 수부터 해야하나? 가장 작은 값을 가진 원소가 답이 될 수 없으므로,
제일 큰 수부터 탐색하면 언젠가??
3개의 수를 선택해서 만들기보다, 집합에서 제일 큰 수부터 만들 수 있는 지 없는 지 생각하면 어떨까?
5
2
4
5
12
13

*/

#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;
typedef long long int LLI;

int main() {
    int N;
    cin >> N;
    unordered_set<LLI> s, n;
    LLI list[1000];
    for (int i = 0; i < N; i++) {
        cin >> list[i];
        n.emplace(list[i]);
    }
    // 두 개의 합을 미리 저장한 후 그걸 순회하며 탐색
    sort(list, list + N);
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            s.emplace(list[i] + list[j]);
        }
    }
    for (int i=N-1; i>=0; i--) {
        // list[i] = n? + s?
        for (int j = i-1; j>=0; j--) {
            LLI t = list[i];
            if (s.count(t - list[j])) {
                cout << t;
                return 0;
            }
        }
    }
}
