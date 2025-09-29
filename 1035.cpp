/*
답을 보고 풀었다...
수학적 공식을 통해 답을 구할 수 있을거라 생각했지만, 그게 아니었다. 가능한 경우를 모두 구한다음 그 중에 최적해를 선택하는 문제였다.
-----
조각들 중에 다른 조각들과의 거리가 가장 가까운 조각을 중심으로 뭉치기?
이동시키는게 맞나? 어차피 이동거리만 계산한다면...
맵에서 조각들의 위치를 이동시키면서 가능한 모든 조합을 만든다.
그 조합에서 연결요소가 될 때 각 점과의 최소 거리를 계산한다.
 */

#include <iostream>
#define INF 100000007

using namespace std;

int coord[5][2], N = 0;
bool map[7][7];

int min(int a, int b) {
    return a > b ? b : a;
}

int abs(int a) {
    return a > 0 ? a : -a;
}

int dfs(int x, int y) {
    if (!map[y][x]) {
        return 0;
    }
    map[y][x] = false;
    return 1 +
           dfs(x - 1, y) +
           dfs(x + 1, y) +
           dfs(x, y - 1) +
           dfs(x, y + 1);
}

bool check_connection(int mask) {
    for (int i = 0; i < 25; i++) {
        map[i / 5 + 1][i % 5 + 1] = 1 << (24 - i) & mask;
    }
    for (int y = 1; y <= 5; y++) {
        for (int x = 1; x <= 5; x++) {
            if (map[y][x] && dfs(x, y) == N) {
                return true;
            }
        }
    }
    return false;
}

int get_dist(int mask) {
    int mcoord[5][2];
    int j = 0;
    for (int i = 0; i < 25; i++) {
        if (1 << i & mask) {
            mcoord[j][0] = i % 5;
            mcoord[j][1] = i / 5;
            j++;
        }
    }
    int res = 0, dist, M = N, k = 0;
    for (int i = 0; i < N; i++) {
        dist = INF;
        for (j = 0; j < M; j++) {
            // TODO: 이 방식이 항상 최소 이동거리를 얻어내는가?
            int T = abs(coord[i][0] - mcoord[j][0]) + abs(coord[i][1] - mcoord[j][1]);
            if (dist > T) {
                k = j;
                dist = T;
            }
        }
        if (M > 0) {
            mcoord[k][0] = mcoord[M - 1][0];
            mcoord[k][1] = mcoord[M - 1][1];
        }
        M--;
        res += dist;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cout.tie(0);
    char str[6];
    for (int i = 0; i < 5; i++) {
        cin >> str;
        for (int j = 0; j < 5; j++) {
            if (str[j] == '*') {
                coord[N][0] = j;
                coord[N][1] = i;
                N++;
            }
        }
    }

    int mdist = INF;
    int arr[5];
    int END = 0;
    for (int i = 0; i < N; i++) {
        arr[i] = N - i - 1;
        END |= 1 << (24 - i);
    }

    int mask = 0;
    arr[0] = -1;
    while (mask != END) {
        if (arr[0] == 24) {
            // 바꿔야할 인덱스 찾기
            int i = 0;
            while (arr[i] + i == 24 && i < N) {
                i++;
            }
            arr[i--]++;
            while (i >= 0) {
                arr[i] = arr[i + 1] + 1;
                i--;
            }
        } else {
            arr[0]++;
        }
        mask = 0;
        for (int i = 0; i < N; i++) {
            mask |= 1 << arr[i];
        }
        // 2. 현재 배치가 연결요소를 이루는지 검사
        if (check_connection(mask)) {
            // 3. 연결요소가 된다면 각 점과의 거리 계산 후 최소 거리 갱신
            int dist = get_dist(mask);
            if (mdist > dist) {
                mdist = mdist < dist ? mdist : dist;
            }
        }
    }

    cout << mdist;
}
