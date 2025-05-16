/*
길이가 1000000으로 늘어남 n^2로는 절대 안됨
{1, ... n-1}개의 수열이 있다고 하고, n번째 원소를 추가한다면? 이전 수열에서 제일 큰 LIS를 찾아 1을 더하면 됨
전체 집합에서 n번째 원소의 값보다 작은 원소들 중 최대의 LIS길이 + 1 = n의 LIS 길이
n이 1000이면 그냥 선형탐색하면 되지만, 이번엔 안됨.
찾는 방법을 log로 바꿔야함...

-----
힌트: DP없이 오로지 이분탐색으로 판단해야함
이분탐색을 n번해야겠지?
nlogn으로 개선하려면?
8
5 4 3 1 7 3 2 5
1 1 1 1 2 2 2 3
---
답: LIS의 형태를 유지하기 위해 주어진 배열의 인덱스를 하나씩 살펴보면서,
  그 숫자가 들어갈 위치를 이분탐색으로 탐색해서 넣는다.
LIS의 길이만 구하게 됨.
8
5 6 7 1 2 3 4 5
5
1 2 3 1 4
lower_bound, upper_bound, binary_search의 차이 알기
 */
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    int arr[1000000];
    int res[1000000];
    cin >> arr[0];
    res[0] = arr[0];
    int s = 0;
    for (int i = 1; i < N; i++) {
        cin >> arr[i];
        if (res[s] < arr[i]) {
            res[++s] = arr[i];
        } else {
            int* p = lower_bound(res, res + s, arr[i]);
            *p = arr[i];
        }
    }

    cout << s + 1;
}
