/*
7 3
1 2 3 4 5 6 7
    1     2
  3         4
        5
6     7
원형 큐
 */

#include <iostream>
using namespace std;
struct Node {
    Node* next;
    int val;
};
int N, M;
Node* head;
void insert(Node* node, int val) {
    node->next = new Node();
    node->next->val = val;
}
Node* pop(Node* node) {
    Node* next = node->next;
    if (next == nullptr) {
        node->next = nullptr;
        return nullptr;
    }
    node->next = next->next;
    return next;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    Node* head = new Node();
    Node* iter = head;
    for (int i=0;i<N; i++) {
        insert(iter, i+1);
        iter = iter->next;
    }
    iter->next = head->next;

    int arr[5001], size = 0;
    while (iter->next != nullptr) {
        for (int j=0;j<M-1; j++) {
            iter = iter->next;
        }
        Node* node = pop(iter);
        arr[size++] = node->val;
        //
        if (node->next == node) {
            arr[size++] = node->val;
            break;
        }
    }

    cout << '<';
    for (int i=0; i<N-1; i++) {
        cout << arr[i] << ", ";
    }
    cout << arr[N-1] << '>';
}
