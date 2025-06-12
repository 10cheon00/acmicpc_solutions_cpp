// 민식어는 a b k d e g h i l m  n ng  o  p  r  s  t  u  w  y의 순서이다.
//        0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
// 이걸 알파벳 순으로 정렬하고, 정렬하기 전에 순서값을 부여하고 그걸 기반으로 문자열들을 사전순으로 정렬
// .. k를 c로 바꾸고 ng를 o로, o이상의 문자들에 1을 더하기.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<pair<string, string>> list;
    for (int i=0; i<N;i++) {
        string s1, s2;
        cin >> s1;
        s2 = s1;
        for (int i=0; i<s1.size(); i++) {
            if (s1[i] == 'k') {
                s1[i] = 'c';
            } else if (i+1 < s1.size() && s1[i] == 'n' && s1[i+1] == 'g') {
                s1[i] = 'o';
            } else if (s1[i] > 'n') {
                s1[i]++;
            }
        }
        list.emplace_back(s1,s2);
    }
    sort(list.begin(),list.end());
    for (auto p : list) {
        cout << p.second << '\n';
    }
}
