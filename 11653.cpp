/*
 * 11653 ���μ�����
 * �ǹ�V
 */

#include <iostream>

using namespace std;

int main() {
    int number, prime = 2;
    cin >> number;
    while (number > 1) {
        if (number % prime > 0) {
            prime++;
        }
        else {
            cout << prime << endl;
            number /= prime;
            prime = 2;
        }
    }
}