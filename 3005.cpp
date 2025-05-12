#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    cin.ignore();
    char map[20][20] = {0};
    int state[20][20] = {0};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            map[i][j] = cin.get();
        }
        cin.get();
    }
    set<string> dict;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // 1이면 왼쪽으로 조사 완료한 것
            // 2면 위쪽으로 조사 완료한 것
            if (map[i][j] == '#') {
                continue;
            }
            if ((state[i][j] & 1) == 0) {
                string str;
                for (int k = j; k < M; k++) {
                    if (map[i][k] == '#') {
                        break;
                    }
                    str += map[i][k];
                    state[i][k] |= 1;
                }
                if (str.size() > 1) {
                    dict.emplace(str);
                }
            }
            if ((state[i][j] & 2) == 0) {
                string str;
                for (int k = i; k < N; k++) {
                    if (map[k][j] == '#') {
                        break;
                    }
                    str += map[k][j];
                    state[k][j] |= 2;
                }
                if (str.size() > 1) {
                    dict.emplace(str);
                }
            }
        }
    }
    cout << *dict.begin();
}
