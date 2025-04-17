/*
스티커 두 개를 고르고 두 스티커를 붙였을 때 넓이를 구하기
전체 N개에서 2개를 고르는 경우는 n(n-1)이니까.. O(N^2)가 된다.
*/
#include <iostream>
using namespace std;

struct Box {
    int l, b, r, t;
};


bool AABB(Box &b1, Box &b2) {
    return b1.r > b2.l && b1.t > b2.b;
}

int AREA(Box &b) {
    return (b.r - b.l) * (b.t - b.b);
}

int main() {
    int H, W, N, R[100], C[100], res = 0;
    cin >> H >> W >> N;
    for (int i = 0; i < N; i++) {
        cin >> R[i] >> C[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            // 영역의 좌하단(0,0),우상단(H,W)에 각각 붙이려고 한다
            // 각 스티커마다 회전해서 붙였을 때, 4가지 경우를 조사해야함
            // ab,Ab,aB,AB
            // 이렇게 설정한 상자들끼리 aabb하면 된다.
            // 하지만 모눈종이를 벗어나면 안되니까...
            Box b[4] = {
                {0, 0, R[i], C[i]},
                {0, 0, C[i], R[i]},
                {W - C[j], H - R[j], W, H},
                {W - R[j], H - C[j], W, H},
            };
            for (int k = 0; k < 2; k++) {
                for (int l = 2; l < 4; l++) {
                    if (b[k].r > W || b[k].t > H || b[l].l < 0 || b[l].b < 0) {
                        continue;
                    }
                    if (!AABB(b[k], b[l])) {
                        int area = AREA(b[k]) + AREA(b[l]);
                        if (res < area) {
                            res = area;
                        }
                    }
                }
            }
        }
    }
    cout << res;
}
