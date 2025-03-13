#include <cmath>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (1) {
    int n, m, o = 0;
    cin >> n;
    if (n == 0) {
      break;
    }
    m = n;
    while (m) {
      o *= 10;
      o += m % 10;
      m /= 10;
    }
    if (o == n) {
      cout << "yes" << '\n';
    } else {
      cout << "no" << '\n';
    }
  }
}