/*
평균 점수가 N개 주어질 때 최소 응답 인원 수 K를 구하기
응답 값은 0~10사이 정수
2
0.500
0.300
2
0.500
0.301
평균 점수에 인원수를 곱하면 항상 정수가 됨
소수셋째 자리에서 잘라냈다고 했으므로 평균점수/K, 평균점수+0.0009/K 사이에 정수가 있는지 구하기
0.0009가 아니라 0.000999를 더해야 정수가 바뀌는 경우가 있음
소수점 계산 시 오차가 생길 수 있어 문자열로 입력 후 정수로 변환
0.000999를 더한 후 계산해야하므로 강제로 1000000을 곱하기
 */
#include <iostream>
typedef long long LL;
using namespace std;

int ctoi(char c) {
    return c - '0';
}

// #.######
// 10000000 => 10.000000
int to_int(char str[10]) {
    if (str[1] == '.') {
        return ctoi(str[0]) * 1000000 +
               ctoi(str[2]) * 100000 +
               ctoi(str[3]) * 10000 +
               ctoi(str[4]) * 1000;
    }
    return 10000000;
}

int main() {
    int N;
    LL arr[50];
    cin >> N;
    for (int i = 0; i < N; i++) {
        char str[10];
        cin >> str;
        arr[i] = to_int(str);
    }
    for (int K = 1; K <= 1000; K++) {
        bool valid = true;
        for (int i = 0; i < N; i++) {
            LL S1 = arr[i] * K, S2 = (arr[i] + 999) * K;
            // 평균점수*K == 정수 판별
            if (!(S1 % 1000000 == 0 || S2 / 1000000 - S1 / 1000000 >= 1)) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << K;
            return 0;
        }
    }
}
