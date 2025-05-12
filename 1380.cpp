#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int M = 0;
    while (1) {
        int N;
        cin >> N;
        if (N == 0) {
            return 0;
        }
        cin.ignore();
        vector<string> s;
        for (int i=0; i<N; i++) {
            string str;
            getline(cin, str);
            s.emplace_back(str);
        }
        bool check[100] = {false};
        for (int i=0; i<2*N-1; i++) {
            int j;
            char a;
            cin >> j >> a;
            check[j-1] = !check[j-1];
        }

        for (int i=0; i<N; i++) {
            if (check[i]) {
                cout << ++M << ' ' << s[i] << '\n';
                break;
            }
        }
    }
}