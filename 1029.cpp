
// 답을 보고 풀었다...

#include <iostream>
#define MAX 10000
using namespace std;

int N;
int graph[15][15];
int dp[15][1 << 15];

int min(int a, int b) { return a < b ? a : b; }

int getCount(int mask) {
  int n = 0;
  while (mask > 0) {
    n += mask & 1;
    mask >>= 1;
  }
  return n;
}

// 지금까지 그림을 구매했었던 사람들의 집합이 mask라면,
// dp[j][mask]는 j번째 구매자가 산 그림의 최소가격
// 거래가 성립하지 않는 경우를 제외하고, 최대한 구매 가격이 낮아지도록 dp 수행
// 그 다음에 거래 내역(dp에 저장된 값)을 보고 mask에 있는 구매자 수를 카운팅 후 최대값 찾기
void solution(int i, int visited) {
  for (int j = 0; j < N; j++) {
    // 내가 나에게 판매하는 경우,
    // 한 번 구매했었던 사람이 다시 구매하려는 경우는 건너뜀
    if (i == j || (visited & (1 << j))) {
      continue;
    }

    // i가 이전 거래에서 구매했었던 가격이 A, j가 i에게서 구입하는 가격이 B라면,
    // B < A 일 때 거래가 성립하지 않으므로 건너뜀
    int prevCost = dp[i][visited];
    int cost = graph[i][j];
    if (cost < prevCost) {
      continue;
    }

    // j가 구입하려고 하는 가격이 dp에 저장된 값보다(이전에 계산했었던 가격보다)
    // 싼 경우에만 갱신하고 재귀 수행
    int mask = visited | (1 << j);
    if (cost < dp[j][mask]) {
      dp[j][mask] = cost;
      solution(j, mask);
    }
  }
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    char str[16];
    cin >> str;
    for (int j = 0; j < N; j++) {
      graph[i][j] = str[j] - '0';
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 1 << N; j++) {
      dp[i][j] = MAX;
    }
  }
  dp[0][1] = 0;
  solution(0, 1);

  int max = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 1 << N; j++) {
      if (dp[i][j] != MAX) {
        int cnt = getCount(j);
        max = max > cnt ? max : cnt;
      }
    }
  }
  cout << max;
}