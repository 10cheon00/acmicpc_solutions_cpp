/*
001
001
위의 상태를 가정.
K가 홀수라면 111을 못만들겠지.
K가 2라면 당연히 0을 1로 바꾸면 되므로 1열,2열을 선택.
하지만 K가 4라면 같은 열을 두번 선택하면 됨.

0001
0001
K가 짝수라면 1111을 못만든다.
위의 상태에 K가 3이라면 당연히 1,2,3열을 선택.
이 때 K가 5라면? 같은 열을 두 번 선택하면 K가 3일때랑 같음

따라서 0의 개수를 기억하고, K가 짝수면 0의 개수가 짝수이고 K보다 적은 행을,
K가 홀수면 0의 개수가 홀수이고 K보다 적은 행을 선택한다.
결과를 만들려면 불을 켤 수 있는 행의 최대 개수를 찾아야함.
그런 행이 책상에 몇개나 있을지 알고 있는 상태에서 위의 행의 개수가 최대인 행을 선택하면 된다.
 */
#include <iostream>
#include <map>
#include <cstring>
using namespace std;
typedef pair<int, int> PII;

int getZeros(string &str) {
    int zeroCounter = 0;
    for (char i: str) {
        if (i == '0') {
            zeroCounter++;
        }
    }
    return zeroCounter;
}

int main() {
    int N, M, K;
    string str;
    map<string, PII> m; // <행의 구조, <0의 개수, 책상에서 그 행의 개수>>
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> str;
        auto iter = m.find(str);
        if (iter != m.end()) {
            iter->second.second++;
        } else {
            m.insert({str, make_pair(getZeros(str), 1)});
        }
    }
    cin >> K;
    int max = 0;
    for (auto iter = m.begin(); iter != m.end(); ++iter) {
        if (iter->second.first <= K) {
            if (K % 2 == 0) {
                // 0의 개수가 짝수
                if (iter->second.first % 2 == 0) {
                    max = max > iter->second.second ? max : iter->second.second;
                }
            } else {
                // 0의 개수가 홀수
                if (iter->second.first % 2) {
                    max = max > iter->second.second ? max : iter->second.second;
                }
            }
        }
    }
    cout << max;
}
