/*
이전에는 그냥 높은 자리수에 문자가 나오면 높은 숫자를 부여하려 했지만,
  문자의 등장 횟수도 높은 숫자를 받는 것에 영향을 준다.

반례를 찾다가 알게 되었는데,
1의 자리에서 등장횟수가 10개 초과인 문자는, 10의 자리에서 등장횟수가 1개인 문자보다 더 큰 값이 될 수 있다.
이 부분을 간과하고 있었다!
따라서 낮은 자리수라 하더라도 등장 횟수에 따라서 더 높은 가중치가 될 수 있다는 점이다.
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef long long LL;
#define ctoi(c) (c - 'A')

LL pow(LL b, int e) {
    if (e == 0) {
        return 1;
    }
    LL r = b;
    for (int i = 1; i < e; i++) {
        r *= b;
    }
    return r;
}

char str[50][13];
int N;
int cmap[10];

void print() {
    long long res = 0;
    for (int i = 0; i < N; i++) {
        long long num = 0;
        for (int j = 0; str[i][j]; j++) {
            num = num * 10L + cmap[ctoi(str[i][j])];
        }
        cout << num << '\n';
        res += num;
    }
    cout << res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // i = A~J, j = 0~11번째 자리
    // 123이면 count[3][0], count[2][1], count[1][2]
    int count[10][12];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 12; j++) {
            count[i][j] = 0;
        }
    }

    cin >> N;
    set<char> nonzero;
    for (int i = 0; i < N; i++) {
        cin >> str[i];
        int len = -1;

        while (str[i][++len]);
        for (int j = 0; str[i][j]; j++) {
            char c = str[i][j];
            count[ctoi(c)][len - j - 1]++;
        }
        nonzero.emplace(str[i][0]);
    }
    // 자리수와 등장횟수에 따른 정렬?
    vector<pair<LL, char> > list;
    for (int i = 0; i < 10; i++) {
        LL w = 0;
        for (int j = 11; j >= 0; j--) {
            w += pow(10LL, j) * count[i][j];
        }
        if (w > 0) {
            list.emplace_back(w, i + 'A');
        }
    }

    // 가중치에 따라 정렬, 오름차순이 됨.
    sort(list.begin(), list.end());
    if (list.size() == 10) {
        // 0이 될 수 없는 경우를 처리
        // 0이 될 수 있는 수중 가장 작은 가중치의 값을 제일 아래로 이동시키기
        vector<pair<LL, char> >::iterator minIter = list.end();
        for (auto iter = list.begin(); iter != list.end(); ++iter) {
            if (nonzero.find(iter->second) == nonzero.end()) {
                if (minIter == list.end()) {
                    minIter = iter;
                } else if (minIter->first > iter->first) {
                    minIter = iter;
                }
            }
        }
        char c = minIter->second;
        list.erase(minIter);
        list.emplace(list.begin(), 0, c);
    }
    // 0번째부터 제일 낮은 숫자 부여하기
    int num = 10 - list.size();
    for (auto iter = list.begin(); iter != list.end(); ++iter) {
        cmap[ctoi(iter->second)] = num++;
    }
    print();
}
