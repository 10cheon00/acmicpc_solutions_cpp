/*
anta + ? + tica
acint는 무조건 가르쳐야 함 == K가 5 이상이어야 함.
anta와 tica를 제외한 나머지 문자열에서 acint를 제외한 나머지 글자의 개수가 K보다 같거나 작은 단어만 가능
하지만 단어풀중에서 특정 글자를 가르쳤다고 선택했지만, 가르칠 수 있는 단어를 최대로 만들지 않을 수 있음.
각 단어마다 사용된 글자 수는 전제조건이며, 글자 수가 정확히 K와 같더라도 글자의 종류에 따라 가르칠 수 있는 단어의 최대 수가 달라짐.
b
bd
bdr
br
bx
bxy
by
dr

질문 게시판을 보고 답을 얻었다.
... trie로 찾아보려면 힘들다.
N=50, 단어의 길이=15, K=26
21개중에 10개를 골라 나열하는 경우의 수 = 21C10 = 352716(최대 경우의 수)
그냥 무식하게 위 경우의 수를 만들어 검사하면 된다. 문자열 검사를 하지 않는 대신 비트 연산으로 단순화시키자.
*/
#include <iostream>
using namespace std;

unsigned int words[50];
int N, K;
int maxWord = 0;

// a,c,i,n,t를 쓰지 않을 것이므로 비트마스킹에서 빈공간 없애주기
int alphabet2Bit(char c) {
    if (c > 't') return 'z' - c;
    if (c > 'n') return 'z' - c - 1;
    if (c > 'i') return 'z' - c - 2;
    if (c > 'c') return 'z' - c - 3;
    return 'z' - c - 4;
}

void check(int length, int s, unsigned int comb) {
    if (length == K - 5) {
        // check
        int count = 0;
        for (int i=0; i<N; i++) {
            if ((comb | words[i]) == comb) {
                // printf("%d | %d == %d\n", comb, words[i], comb | words[i]);
                count++;
            }
        }
        maxWord = maxWord > count ? maxWord : count;
        return;
    }

    for (int i = s; i < 21; i++) {
        check(length + 1, i + 1, comb | 1U << i);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    char str[16];

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> str;
        words[i] = 0U;
        for (int j = 0; str[j]; j++) {
            if (str[j] == 'a' ||
                str[j] == 'c' ||
                str[j] == 'i' ||
                str[j] == 'n' ||
                str[j] == 't') {
                continue;
            }

            // ex. bdf = ?
            //            bdefghjklmopqrsuvwxyz
            // 00000000000110100000000000000000
            words[i] |= 1 << alphabet2Bit(str[j]); // 제일 왼쪽(20번째)을 b, 제일 오른쪽(0번째)를 z
        }
    }
    if (K < 5) {
        cout << 0;
        return 0;
    }

    check(0, 0, 0U);
    cout << maxWord;
}
