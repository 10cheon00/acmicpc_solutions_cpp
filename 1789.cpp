/*
 * 1789 ��������
 * �ǹ�V
 */

#include <iostream>
using namespace std;

int main() {
    long long S, number = 1, N = 0;
    cin >> S;
    while (true) {
        S -= number++;
        N++;
        if (S - number < 0) {
            break;
        }
    }
    cout << N;
}
/*

16 = 1+2+3+4+5 +1, �ִ밪=5

*/