/*
부분 문자열 전체를 단순 비교하지 않고, 모든 부분 문자열이 주어진 순열의 모든 원소를 포함하고 있는지 확인
찾아낸 부분문자열이 이미 찾았던 패턴과 일치하는지 확인
ABB
cccAAB
부분 문자열을 string으로 만들고 그걸 set에 조회?
길이 3000의 W에 대해서 미리 3000!개를 set에 다 넣어야 하는데 ...

순열에 대한 개수정보를 배열로 관리, 부분문자열을 만들면서 새로운 배열에 저장
모든 개수가 일치하면 일치하는 순열. 이 때 만들어진 부분 문자열을 set에 넣기
 */

#include <iostream>
#include <string>
#include <map>
using namespace std;
int char2index(char c) {
    if (c < 'a') {
        return c - 'A';
    }
    return c - 'a' + 26;
}
int main() {
    int w, s;
    string W, S;
    cin >> w >> s;
    cin >> W >> S;

    map<string, int> subs;
    int word[52], sub[52];
    for (int i = 0; i < 52; i++) {
        word[i] = sub[i] = 0;
    }
    for (int i = 0; i < W.size(); i++) {
        word[char2index(W.at(i))]++;
        sub[char2index(S.at(i))]++;
    }
    for (int i = 0; i + W.size() <= S.size(); i++) {
        bool equal = true;
        for (int j = 0; j < 52; j++) {
            if (word[j] != sub[j]) {
                equal = false;
                break;
            }
        }
        if (equal) {
            string equalstr = S.substr(i, W.size());
            subs[equalstr]++;
        }
        if (i + W.size() < S.size()) {
            sub[char2index(S.at(i))]--;
            sub[char2index(S.at(i + W.size()))]++;
        }
    }
    int size = 0;
    for (auto p : subs) {
        size += p.second;
    }
    cout << size;
}
