/*
(100~1~|01)~
10...1...
1...10?
1...100...
1...101.
0
 */
#include <iostream>
using namespace std;

bool is_noise(char *str) {
    int i = 0;
    while (str[i]) {
        if (str[i] == '0') {
            if (str[i + 1] == '1') {
                i += 2;
            } else {
                return true;
            }
        } else if (str[i] == '1') {
            if (str[i + 1] == '0') {
                // 100...
                if (str[i + 2] == '0') {
                    i += 2;
                    while (str[i] == '0') {
                        i++;
                    }
                    if (!str[i]) {
                        return true;
                    }
                    // 100...1...
                    while (str[i] == '1') {
                        i++;
                    }
                    if (!str[i]) {
                        return false;
                    }
                    if (str[i] == '0') {
                        if (str[i + 1] == '1') {
                            // 100...1...101
                            //            i
                            i += 2;
                        } else if (str[i + 1] == '0') {
                            if (str[i - 2] == '1') {
                                // 100...1100
                                //         i
                                i--;
                            } else {
                                // 100...0100?
                                //         i => NOISE
                                return true;
                            }
                        } else {
                            return true;
                        }
                    }
                } else {
                    return true;
                }
            } else {
                return true;
            }
        }
    }
    return false;
}

int main() {
    char str[151];
    cin >> str;
    cout << (is_noise(str) ? "NOISE" : "SUBMARINE");
}
