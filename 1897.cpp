/*
trie? 그래프?
단어가 주어질 때 만들 수 있는지 없는지 판별해야한다.
9 cal
cal
calf
calfs
call
calls
choral
chorale
coal
coral

cal -> calf -> calfs
    -> call -> calls
    -> coal -> coral -> choral -> chorale

abc -> abcd -> abced?
    -> abce -> abced?

cal
calf
call
coal
calfs
calls
coral
choral
chorale

 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
bool compare(const string& s1, const string& s2) {
    if (s1.size() == s2.size()) {
        return s1 < s2;
    }
    return s1.size() < s2.size();
}
int main() {
    unordered_set<string> dict;
    vector<string> list;
    string str;
    int N;
    cin >> N >> str;
    dict.emplace(str);
    for (int i = 0; i < N; i++) {
        cin >> str;
        list.emplace_back(str);
    }
    sort(list.begin(), list.end(), compare);

    for (int i = 0; i < N; i++) {
        // 입력받은 문자에서 한 글자씩 뺀 문자가 사전에 존재하는지 확인.
        // 존재한다면 이 단어를 사전에 추가.
        if (dict.find(list[i]) != dict.end()) {
            continue;
        }

        for (int j = 0; j < list[i].size(); j++) {
            char str2[81] ={0};
            int k = 0, l = 0;
            while (list[i][k]) {
                if (j != k) {
                    str2[l++] = list[i][k];
                }
                k++;
            }
            if (dict.find(str2) != dict.end()) {
                dict.emplace(list[i]);
                break;
            }
        }
    }
    unordered_set<string>::value_type p = *dict.begin();
    for (auto &str: dict) {
        p = str.size() < p.size() ? p : str;
    }
    cout << p;
}
