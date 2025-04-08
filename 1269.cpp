#include <iostream>
#include <set>
using namespace std;
int main() {
    int N, M, t;
    cin >> N >> M;
    set<int> A, B;
    for (int i=0;i<N; i++) {
        cin >> t;
        A.insert(t);
    }
    for (int i=0;i<M;i++) {
        cin >> t;
        if (A.find(t) == A.end()) {
            B.insert(t);
        } else {
            A.erase(t);
        }
    }
    cout << A.size() + B.size();
}