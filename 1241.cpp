/*
학생이 N명의 학생들의 숫자를 보면서 배수인지 판단
O(N^2)?
배수 판단시에는 순서가 딱히 정해져 있지 않음.
"자신이 쓴 숫자가 다른 사람이 쓴 숫자의 배수이면"
arr[i] == k * arr[j]
자신보다 낮은 숫자들의 인원들을 살펴보는 것은 시간 초과
10 = {1,2,5,10}
24 = {1,2,3,4,6,8,12,24}
인수분해로 얻은 숫자들의 총합만 구하면 됨
*/
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, t;
    cin >> N;
    int nums[1000001] = {0};
    int arr[1000000] = {0};
    for (int i = 0; i < N; i++) {
        cin >> t;
        arr[i] = t;
        nums[t]++;
    }
    for (int i = 0; i < N; i++) {
        // 약수 집합을 구하는 알고리즘의 최선은?
        // 4 = {1,2,4}
        int M = 0;
        for (int j = 1; j * j <= arr[i]; j++) {
            if (arr[i] % j == 0) {
                if (j * j != arr[i]) {
                    M += nums[arr[i] / j];
                }
                M += nums[j];
            }
        }
        cout << M - 1<< '\n';
    }
}
