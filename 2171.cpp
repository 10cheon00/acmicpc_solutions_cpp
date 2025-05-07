/*
x축, y축에 평행한 사각형의 개수 찾기
무작정 N개에서 4개의 조합찾기면...
5000c4 = 260104280000000000000....
어느 한 점을 시작으로 전체 탐색을 하지 않도록 만들기
   *     *

   *   *     *

   *   * *   *
어느 점에서 축과 평행한 다른 점이 있는지 계속 중복탐색한다.
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, x, y, cnt = 0;
    map<int, vector<int> > m;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        m[x].emplace_back(y);
    }
    for (auto &iter1: m) {
        vector<int> &list = iter1.second;
        sort(list.begin(), list.end());
    }
    for (auto iter1 = m.begin(); iter1 != m.end(); ++iter1) {
        vector<int> &x1list = iter1->second;
        for (auto iter2 = next(iter1); iter2 != m.end(); ++iter2) {
            vector<int> &x2list = iter2->second;
            int i = 0, j = 0;
            while (i < x1list.size() && j < x2list.size()) {
                int k = i + 1, l = j + 1, y1 = x1list[i], y2 = x2list[j];
                if (y1 < y2) {
                    i++;
                    continue;
                }
                if (y1 > y2) {
                    j++;
                    continue;
                }
                while (k < x1list.size() && l < x2list.size()) {
                    int y3 = x1list[k], y4 = x2list[l];
                    if (y3 < y4) {
                        k++;
                        continue;
                    }
                    if (y3 > y4) {
                        l++;
                        continue;
                    }
                    cnt++;
                    k++;
                    l++;
                }
                i++;
                j++;
            }
        }
    }
    cout << cnt;
}
