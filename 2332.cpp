/*
1 ij	2 abc	3 def
4 gh	5 kl	6 mn
7 prs	8 tuv	9 wxy
        0 oqz
전화번호 100자리
단어 수는 50000
단어 길이는 50
단어가 주어지면 해당 단어를 전화번호로 치환하고, 이 때 항상 제일 첫번째 자리로 치환
 ex. cat = c->2, a->2, t->8
     bat = b->2, a->2, t->8
입력한 전화번호를 1자리부터 m자리까지 해시탐색, 모든 탐색이 끝났을 때에 남는 전화번호가 있으면 No solution.
 ...은 고른 단어의 수가 최소로 결정되지 않음
aaabbbccc
abbbc
aa
cc
하나씩 대입해서 이 문자열이 전화번호와 일치하는지 확인하려면 굉장히 오래 걸릴듯
---
GPT를 보고 답을 제출함.
---
dp[i][c]: S의 [0..i) 구간(즉 길이 i까지)를 정확히 c개의 리스트 문자열로 이어 붙여 만들 수 있으면 true, 아니면 false
최초 dp[0][0]은 공백을 의미하고, 공백은 그냥 만들 수 있다고 가정하여 여기서부터 0~L까지의 문자열이 단어 목록에 있는지 확인
만약 있다면, dp[0+L][1]을 true로 바꾸어 만들 수 있다고 가정. 이런 문자열들을 모두 탐색한 후 dp[i][c]가 true일때까지 2중for문 수행
문자열의 i위치부터 각 단어의 길이 L까지의 문자열이 사전에 있으면, 이미 dp[i][c]로 0~i번째까지는 만들 수 있다고 가정했으므로,
 i+L까지의 부분 문자열은 c+1개만큼으로 만들 수 있다는 의미
그렇게 마지막 i==S.size()까지 반복 후 dp[S.size][c]가 true인 최소 c를 찾아내면 됨.

==> dp[i][c]가 참이라면, 0~i까지는 아무튼 c개로 만들 수 있었음을 의미한다.
 */
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
int map[26] = {2, 2, 2, 3, 3, 3, 4, 4, 1, 1, 5, 5, 6, 6, 0, 7, 0, 7, 7, 8, 8, 8, 9, 9, 9, 0};

string convert(string word) {
    const char *str = word.c_str();
    string res;

    for (int i = 0; str[i]; i++) {
        res += '0' + map[str[i] - 'a'];
    }
    return res;
}

int main() {
    int N;
    string phone;
    cin >> phone >> N;
    vector<string> words; // 단순 단어 목록
    vector<string> phones; // 변환한 번호 목록
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        string s = convert(word);
        words.emplace_back(word);
        phones.emplace_back(s);
    }
    vector<int> dp[101][101];
    dp[0][0].emplace_back(0);
    int m = phone.size();
    for (int i = 0; i < m; i++) {
        for (int c = 0; c < m; c++) {
            if (dp[i][c].size() == 0) continue;
            for (int w = 0; w < N; w++) {
                int L = phones[w].size();
                if (i + L > m) continue; // 주어진 전화번호보다 길이가 길면 건너뛰기
                if (phone.substr(i, L).compare(phones[w]) == 0) {
                    dp[i + L][c + 1] = dp[i][c];
                    dp[i + L][c + 1].emplace_back(w);
                }
            }
        }
    }
    for (int i = 0; i <= m; i++) {
        for (int c = 0; c <= m; c++) {
            if (dp[m][c].size() > 0) {
                cout << c << '\n';
                for (int i=1; i<dp[m][c].size(); i++) {
                    cout << words[dp[m][c][i]] << '\n';
                }
                return 0;
            }
        }
    }
    cout << "0\nNo solution.";
}
