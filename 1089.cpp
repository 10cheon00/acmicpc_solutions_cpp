/*
꺼져있는 전구가 사실은 고장난 상태라면, 원래는 켜져 있을 수도 있다.
꺼진 전구를 켰을 때 숫자를 만들 수 있다면?
각 자리수에 해당하는 전구판마다 가능한 숫자들을 기억하고,
 일의 자리에 위치한 전구판부터 가능한 조합을 모두 만든다.
N=9인데 모든 전구의 불이 꺼진 상태라면, 각 자리수에 0~9가 다 들어간다.
 = 시간초과
가능한 조합의 수를 구하는게 아니라 평균을 구하는 것이므로,
 이전에 계산한 값을 재사용해야함
0 3 5 7
0 1 2
0 1 2 3
개수 = 4*3*4
9
###..#.......##..#...#...#.......#.
#.#...........................#....
.##..........##..##..#...........#.
#.#...........#...............#....
#.............#..#...#...#...##..##

answer : 855181026.928571

 */
#include <iostream>
#include <vector>
#include <iomanip>
typedef long long int LLI;

using namespace std;
char str[5][35];
char format[5][40] = {"###...#.###.###.#.#.###.###.###.###.###", "#.#...#...#...#.#.#.#...#.....#.#.#.#.#",
                      "#.#...#.###.###.###.###.###...#.###.###", "#.#...#.#.....#...#...#.#.#...#.#.#...#",
                      "###...#.###.###...#.###.###...#.###.###"};
int cnt[10] = {12, 5, 11, 11, 9, 11, 12, 7, 13, 12};

bool is_format_contain_number(int format_num, int str_digit) {
    for (int y = 0; y < 5; y++) {
        for (int l = 0; l < 3; l++) {
            int x = 4 * format_num + l;
            int xx = 4 * str_digit + l;
            if (str[y][xx] == '#') {
                // 전구판에 있는 전구가 포맷에 없다면 불가능한 수
                if (format[y][x] != '#') {
                    return false;
                }
                // 전구판에 불이 꺼져 있더라도 포맷에 있다면 가능한 경우가 됨
            }
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    vector<int> list[9];
    for (int i = 0; i < 5; i++) {
        cin >> str[i];
    }
    for (int i = 0; i < N; i++) {
        // 자리수별로 꺼진 전구를 켰을 때 가능한 수를 찾기
        for (int j = 0; j < 10; j++) {
            // 전구판의 모든 전구가 포맷에 존재하면 가능한 수?
            if (is_format_contain_number(j, i)) {
                list[i].emplace_back(j);
            }
        }
    }
    // 평균 구하기
    LLI total = 0, size = 1, digit = 1;
    for (int i = 0; i < N; i++) {
        size *= list[i].size();
    }
    for (int i = N - 1; i >= 0; i--) {
        int sum = 0;
        for (int j = 0; j < list[i].size(); j++) {
            sum += list[i][j];
        }
        if (list[i].size() > 0) {
            total += sum * digit * (size / list[i].size());
        }
        digit *= 10;
    }
    if (total == 0) {
        cout << -1;
    } else {
        double ans = (double) total / size;
        printf("%.6f",ans);
    }
}
