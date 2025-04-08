#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    string str, B = "";
    map<string, int> dict;
    int M = 0;
    for (int i = 0; i < N; i++) {
        cin >> str;
        ++dict[str];
        if (M < dict[str]) {
            M = dict[str];
            B = str;
        } else if (M == dict[str] && str < B) {
            B = str;
        }
    }
    cout << B;
}
