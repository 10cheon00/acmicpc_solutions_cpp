#include <iostream>
#include <cstring>
using namespace std;
/*
1. 문자열의 어떤 위치에 어떤 문자를 삽입 (시작과 끝도 가능)
2. 어떤 위치에 있는 문자를 삭제
3. 어떤 위치에 있는 문자를 교체
4. 서로 다른 문자의 위치를 교환 (최대 1번만 사용 가능)
-------------------------------------------
힌트...
문자열의 "부분문제"를 기준으로 상태를 정의(연산으로 생긴 문자열대신, 인덱스 기반 접근)
삽입/삭제/교체는 서로 변환 가능(예: 한쪽에서의 삽입 = 반대쪽에서의 삭제와 유사)
언제까지 돌아야 하는가는, 구간 기반 DP에선 자연스럽게 종료된다.
우선순위 큐 탐색(문자열 그 자체로 다익스트라) 대신, 표의 크기를 다 채우면 답이 나오는 쪽으로 접근
-------------------------------------------
힌트2...
표의 축을 "길이"나 "일치 길이"가 아니라, 원문 문자열의 '어느 구간'을 보고 있는지
-------------------------------------------
인덱스가 단순히 원문 문자열의 구간을 말한다면...?
-------------------------------------------
힌트3...
dp[l][r][used]
[l:r]문자열의 양 끝을 같게 만들면 일치하지 않는 구간이 줄어든다.
이 때 삽입, 삭제, 교체에 따라서 l과 r의 범위를 잘 설정하면 됨
-------------------------------------------
답을 보았따...
 */





#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX 55
#define INF 987654321

int dp[MAX][MAX];
string s;

int solve(int l, int r, string a) {
    if (dp[l][r] != -1)return dp[l][r];
    if (l >= r) return 0;
    int &ret = dp[l][r];
    ret = min({ solve(l + 1, r, a) + 1, solve(l, r - 1, a) + 1, solve(l + 1, r - 1, a) + (a[l] != a[r]) });

    return ret;
}

int main() {
    cin >> s;
    memset(dp, -1, sizeof(dp));

    // 먼저 스왑 없이 1,2,3연산으로만 계산해본다.
    int ans = solve(0, s.size() - 1, s);

    for (int i = 0; i < s.size(); i++) {
        for (int j = i+1; j < s.size(); j++) {
            memset(dp, -1, sizeof(dp));
            // 그다음, 이중포문으로 딱 한번 문자를 바꿔보는 4번째 연산을 모든 경우에 대해 만들어보고
            // 그 결과로 생긴 문자열을 사용하여 다시 1,2,3연산을 수행한다.
            string tmp = s;
            swap(tmp[i], tmp[j]);
            ans = min(ans, solve(0, s.size() - 1, tmp) + 1);
        }
    }
    cout << ans;

}