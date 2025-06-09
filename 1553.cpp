/*
0000000
0123456
1111112
1234562
2222333
3456345
3444556
6456566
*/
#include <iostream>
#include <vector>

using namespace std;
char map[8][7];
bool visit[8][7];
int dominos[67];
int res = 0;

void print() {
    cout << "---------\n";
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 7; j++) {
            if (visit[i][j]) {
                cout << '_';
            } else {
                cout << map[i][j];
            }
        }
        cout << '\n';
    }
    cout << "---------\n";
}

bool invalid(int x, int y) { return x < 0 || y < 0 || x >= 7 || y >= 8 || visit[y][x]; }

int get_number(int x1, int y1, int x2, int y2) {
    int num = (map[y1][x1] - '0') * 10 + map[y2][x2] - '0';
    if (dominos[num]) {
        return num;
    }
    num = (map[y2][x2] - '0') * 10 + map[y1][x1] - '0';
    if (dominos[num]) {
        return num;
    }
    return -1;
}

pair<int, int> find_next() {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 7; x++) {
            if (!visit[y][x]) {
                return {x, y};
            }
        }
    }
    return {-1, -1}; // 모두 덮였으면 종료 신호
}

void solution() {
    // 주어진 좌표에서 가로로 놓거나 세로로 놓는 경우밖에 없음
    // 불가능한 경우는 이미 놓은 도미노를 사용하거나 맵 밖으로 놓으려할 때
    // hint: 다음에 놓을 수 있는지 판단할 칸은 꼭 내가 방금 놓은 칸이 아니어도 된다.
    auto p = find_next();
    if (p.first == -1) {
        res++;
        return;
    }
    int x = p.first, y = p.second, xx = x + 1, yy = y, num;
    if (!invalid(xx,yy)) {
        num = get_number(x, y, xx, yy);
        if (num != -1) {
            dominos[num] = false;
            visit[y][x] = visit[yy][xx] = true;
            // print();
            solution();
            dominos[num] = true;
            visit[y][x] = visit[yy][xx] = false;
        }
    }
    xx = x, yy = y + 1;
    if (!invalid(xx,yy)) {
        num = get_number(x, y, xx, yy);
        if (num != -1) {
            dominos[num] = false;
            visit[y][x] = visit[yy][xx] = true;
            // print();
            solution();
            dominos[num] = true;
            visit[y][x] = visit[yy][xx] = false;
        }
    }
}


int main() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 7; j++) {
            visit[i][j] = false;
        }
    }
    int indexes[28] = {0,  1,  2,  3,  4,  5,  6,  11, 12, 13, 14, 15, 16, 22,
                       23, 24, 25, 26, 33, 34, 35, 36, 44, 45, 46, 55, 56, 66};
    for (int i = 0; i < 28; i++) {
        dominos[indexes[i]] = true;
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 7; j++) {
            cin >> map[i][j];
        }
    }
    solution();
    cout << res;
}
