/*
8
4
3
6
8
7
5
2
1
++++--++-++-----
1234  56 78
    43  6  87521


1234 ?
+-+-+-+-
2134
++--+-+-
3214
+++---+-
4321
++++----
2314
++-+--+-
스택에 들어가는 순서는 정해져있음(1 -> N)
pop할 위치를 정해야함
*/
#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;
    int arr[100000];
    char res[200000];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    stack<int> st;
    int i = 0, j = 0, k = 0;
    // st.push(++j);
    // res[k++] = '+';
    st.push(0);
    while (i < N) {
        if (st.top() == arr[i]) {
            st.pop();
            res[k++] = '-';
            i++;
        } else if (st.top() < arr[i]) {
            st.push(++j);
            res[k++] = '+';
        } else if (j == N) {
            // 스택의 top이 다음에 pop해야할 수보다 작은 경우
            st.pop();
            res[k++] = '-';
        } else {
            cout << "NO";
            // break;
            return 0;
        }
    }
    for (i = 0; i < k; i++) {
        cout << res[i] << '\n';
    }
}
