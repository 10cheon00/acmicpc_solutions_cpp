/*
R = M - S, R % (N-1)은 추가할 밑줄, R / (N-1)은 밑줄의 최소 길이
밑줄을 추가할땐,
소문자밖에 없으면? 사전순으로 빠른 것부터
대문자밖에 없으면? 사전순으로 늦는 것부터
섞여 있으면? 대문자들로 시작하는 단어의 경우 사전순으로 늦는 것부터, 소문자로 시작하는 단어의 경우 사전순으로 빠른 것부터...
마지막 단어 뒤에는 붙이지 못하므로 순서 계산할 때 제외
리스트를 두 개로 설정

A b c D E 10...
대문자 다음에 소문자가 오는 경우 추가할 밑줄이 들어가야함.
A__b_c_D_E
A b c D E 11
A__b__c_D_E
A__b_c_D__E(x)
사전순이므로, 제일 왼쪽부터 더 높은 순위가 되도록 만들어야함.
A_b_c_D_E
^^^     대문자->소문자의 경우 중간에 밑줄이 들어가면 우선순위가 높아짐
A__b_c_D_E
   ^^^  소문자->소문자의 경우 중간에 밑줄이 들어가면 우선순위가 높아짐
소문자->대문자의 경우? 밑줄이 들어가면 오히려 우선순위가 떨어짐
대문자->대문자의 경우에도 동일

위 경우에 따라 밑줄을 다 추가한 경우에도 추가할 밑줄이 남는다면, 뒤에서부터 추가?
A b c D E 12
A__b__c_D_E (11)
A__b__c__D_E
A__b__c_D__E
추가할 땐 당연히 최대 최소 차이가 1이 안되도록, 건너뛰어야 함
사실 뒷단어가 소문자로 시작하는 경우에 모두 1을 더해주었으므로 그렇지 않은 경우에 1을 더하면 된다.
뒷문자가 대문자인 경우에 1을 더한다는 해설과 똑같음
 */
#include <iostream>
#include <vector>
using namespace std;

bool isUpper(string &s) {
    return s[0] < 'a';
    // 단어 안에 대문자가 있는지 생각할 필요가 없는 이유
    // 사전순이므로, 제일 왼쪽에 있는 문자가 순서에 영향을 더 크게 준다.

    // for (int i = 0; i < s.length(); i++) {
    //     if (s[i] < 'a') {
    //         return true;
    //     }
    // }
    // return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    vector<string> words;
    vector<int> lines;
    vector<bool> is_upper;
    int S = 0;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        S += str.length();
        words.emplace_back(str);
        lines.emplace_back(0);
        is_upper.push_back(isUpper(str));
    }
    int L = (M - S) / (N - 1), R = (M - S) % (N - 1);
    for (int i = 1; i < N; i++) {
        lines[i - 1] = L;
        if (!is_upper[i] && R > 0) {
            R--;
            lines[i - 1]++;
        }
    }
    for (int i = N - 1; i > 0; i--) {
        if (R > 0) {
            if (lines[i - 1] == L) {
                lines[i - 1]++;
                R--;
            }
        } else {
            break;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << words[i];
        for (int j = 0; j < lines[i]; j++) {
            cout << '_';
        }
    }
}
