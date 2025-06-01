#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, string>> memento;
    for (int i = 0; i < N; i++) {
        char str[5];
        cin >> str;
        if (str[0] == 't') {
            int t;
            string c;
            cin >> c >> t;
            if (memento.empty()) {
                memento.emplace_back(t, string(c));
            } else {
                string word = memento.rbegin()->second;
                memento.emplace_back(t, word + c);
            }
        } else {
            int d, t;
            cin >> d >> t;
            int j = memento.size() - 1;
            while (j >= 0 && memento[j].first >= t - d) {
                j--;
            }
            if (j < 0) {
                memento.emplace_back(t, "");
            } else {
                memento.emplace_back(t, memento[j].second);
            }
        }
    }
    cout << memento.rbegin()->second;
}
