/*
어떤 박스를 조커박스로 사용할 것인지 잘 선택하면 카드를 옮기는 횟수를 최소로 만들 수 있음
한 박스를 조커박스로 선택한다면 다른 박스는 조커박스가 되지 말아야 함
조커박스를 제외한 나머지 박스에는 같은 색의 카드가 한 박스에만 있어야 함...
3 3
0 0 0
0 0 0
0 0 0
박스에 있는 카드 모두를 꺼내서 다른 박스로 옮기는 것도 역시 1회
조커 박스에 모두 넣기 == 다른 박스로 옮기기
A색 카드를 가진 상자가 3개라면 최소 2번은 움직여야 함 조커 상자가 그 중에 있다면 1번만 움직여도 됨
총 상자 수 - 건드리지 않아도 되는 상자 - 1 = 이동 횟수
건드리지 않아도 되는 상자의 최대값 찾기
건드리지 않아도 되는 상자 = 빈 상자, 딱 1 종류의 색깔 카드만 가지는 상자가 유일할 때
 */
#include <iostream>
using namespace std;
int N, M, res = 2147483647, joker = 0;
int box[50][50];
void solution() {
    int s = 0;
    bool selected[50]={false};
    for (int j = 0; j < N; j++) {
        if (j == joker) {
            s++;
            continue;
        }
        // 상자가 가진 색이 딱 한 개인지 확인
        int idx = 0;
        int cnt = 0;
        for (int k = 0; k < M; k++) {
            if (box[j][k] > 0) {
                cnt++;
                idx= k;
            }
        }
        if (cnt == 1 && !selected[idx]) {
            selected[idx] = true;
            s++;
        } else if (cnt == 0) {
            s++;
        }
    }
    int r = N - s;
    res = res > r ? r : res;
}
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> box[i][j];
        }
    }
    while (joker < N) {
        solution();
        joker++;
    }
    cout << res;
}
