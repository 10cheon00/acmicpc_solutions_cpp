#include <iostream>

using namespace std;

class PQ {
    int arr[100001];
    int size = 0;
public:
    void add(int x) {
        arr[++size] = x;
        for (int i=size; i>1; i/=2) {
            if (arr[i] < arr[i/2]) {
                int t = arr[i];
                arr[i] = arr[i/2];
                arr[i/2] = t;
            } else break;
        }
    }

    int pop() {
        if (size == 0) {
            return 0;
        }

        int top = arr[1];
        arr[1] = arr[size--];
        for (int i=1; i*2<=size;) {
            if (i*2 == size || arr[i*2] < arr[i*2+1]) {
                if (arr[i] > arr[i*2] ) {
                    int t = arr[i];
                    arr[i] = arr[i*2];
                    arr[i*2] = t;
                    i = i*2;
                } else break;
            } else {
                if (arr[i] > arr[i*2+1] ) {
                    int t = arr[i];
                    arr[i] = arr[i*2+1];
                    arr[i*2+1] = t;
                    i = i*2+1;
                } else break;
            }
        }
        return top;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
  PQ pq;
  int n, x;
  cin >> n;
  while(n-->0){
    cin >> x;
    if (x == 0) {
        cout << pq.pop() << '\n';
    }
    else {
        pq.add(x);
    }
  }
}