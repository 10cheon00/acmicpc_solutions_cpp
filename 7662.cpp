/*
그냥 deque로 만든다면?
삭제 = o(1)
삽입 = o(n)
총 시간 = o(n**2)

이중 우선순위를 쓴다면?
삭제 = o(1)
삽입 = o(1)
정렬 = o(logn)
총시간 = o(nlogn)...?
한쪽에서 삽입이 일어나면 반대쪽도 삽입해야함. 삽입은 쉬움
한쪽에서 삭제가 일어나면 반대쪽도 삭제해야하는데, 우선순위 큐 특성 상 반대편 위치가 특정되지 않는다.
그래서 삽입할 때 반대편 위치의 인덱스를 같이 삽입해야함
2
6
I 1
I 2
I 3
D 1
I 4
D -1
7
I 5
I 3
I 4
I 1
I 2
D -1
D 1
*/

#include <iostream>
using namespace std;
typedef struct Node {
    int elem;
    int oppoIdx;
} Node;

Node* create_node(int N) {
    Node* node = new Node();
    node->elem = N;
    return node;
}

void swap_node(Node* heap[], int i, int j) {
    Node* p = heap[i];
    heap[i] = heap[j];
    heap[j] = p;
}

Node* min_heap[1000001];
Node* max_heap[1000001];
int min_size = 0, max_size = 0;

bool gt(Node* a, Node* b) { return a->elem > b->elem; }

bool lt(Node* a, Node* b) { return a->elem < b->elem; }

int insert_sort(Node* heap[], Node* oppoheap[], int i, bool (*compare)(Node*, Node*)) {
    while (i > 1) {
        if (compare(heap[i], heap[i / 2])) {
            oppoheap[heap[i / 2]->oppoIdx]->oppoIdx = i;
            swap_node(heap, i, i / 2);
            i /= 2;
        } else {
            break;
        }
    }
    return i;
}

int insert_min_heap(Node* node) {
    min_heap[++min_size] = node;
    return insert_sort(min_heap, max_heap, min_size, lt);
}

int insert_max_heap(Node* node) {
    max_heap[++max_size] = node;
    return insert_sort(max_heap, min_heap, max_size, gt);
}

void insert_node(int N) {
    Node* min_node = create_node(N);
    Node* max_node = create_node(N);
    int min_idx = insert_min_heap(min_node);
    int max_idx = insert_max_heap(max_node);
    min_node->oppoIdx = max_idx;
    max_node->oppoIdx = min_idx;
}

void remove_sort(Node* heap[], Node* oppoheap[], int i, int size, bool (*compare)(Node*, Node*)) {
    while (i * 2 <= size) {
        if (i * 2 == size || compare(heap[i * 2 + 1], heap[i * 2])) {
            if (compare(heap[i], heap[i * 2])) {
                // 원소 이동 시 연결된 반대쪽 원소에도 인덱스 업데이트
                oppoheap[heap[i * 2]->oppoIdx]->oppoIdx = i;
                oppoheap[heap[i]->oppoIdx]->oppoIdx = i * 2;
                swap_node(heap, i, i * 2);
                i = i * 2;
            } else {
                break;
            }
        } else {
            if (compare(heap[i], heap[i * 2 + 1])) {
                oppoheap[heap[i * 2 + 1]->oppoIdx]->oppoIdx = i;
                oppoheap[heap[i]->oppoIdx]->oppoIdx = i * 2 + 1;
                swap_node(heap, i, i * 2 + 1);
                i = i * 2 + 1;
            } else {
                break;
            }
        }
    }
}

Node* remove_min_heap() {
    Node* top = min_heap[1];
    min_heap[1] = min_heap[min_size];
    max_heap[min_heap[1]->oppoIdx]->oppoIdx = 1;
    min_heap[min_size--] = nullptr;
    remove_sort(min_heap, max_heap, 1, min_size, gt);
    return top;
}

Node* remove_max_heap() {
    Node* top = max_heap[1];
    max_heap[1] = max_heap[max_size];
    min_heap[max_heap[1]->oppoIdx]->oppoIdx = 1;
    max_heap[max_size--] = nullptr;
    remove_sort(max_heap, min_heap, 1, max_size, lt);
    return top;
}

void remove_node(int op) {
    if (min_size == 0) {
        return;
    }
    Node* temp, * node;
    if (op == 1) {
        // 최대값 삭제
        node = remove_max_heap();
        // 최소힙에서 node를 삭제함과 동시에 최소힙의 마지막 원소를 node의 oppoIdx 자리로 삽입 후 정렬
        Node* last = min_heap[min_size];
        min_heap[min_size--] = nullptr;
        // 삽입 시, 마지막 원소가 node라면 그만 두기
        if (min_size < node->oppoIdx) {
            return;
        }
        temp = min_heap[node->oppoIdx];
        min_heap[node->oppoIdx] = last;
        max_heap[last->oppoIdx]->oppoIdx = node->oppoIdx;
        // 삽입 시 인덱스 변경
        max_heap[last->oppoIdx]->oppoIdx = insert_sort(min_heap, max_heap, node->oppoIdx, lt);
    } else {
        // 최소값 삭제
        node = remove_min_heap();
        // 최대힙에서 node를 삭제함과 동시에 최대힙의 마지막 원소를 node의 oppoIdx 자리로 삽입 후 정렬
        Node* last = max_heap[max_size];
        max_heap[max_size--] = nullptr;
        // 삽입 시, 마지막 원소가 node라면 그만 두기
        if (max_size < node->oppoIdx) {
            return;
        }
        temp = max_heap[node->oppoIdx];
        max_heap[node->oppoIdx] = last;
        min_heap[last->oppoIdx]->oppoIdx = node->oppoIdx;
        // 삽입 시 인덱스 변경
        min_heap[last->oppoIdx]->oppoIdx = insert_sort(max_heap, min_heap, node->oppoIdx, gt);
    }
    delete node;
    delete temp;
}

void release() {
    for (int i = 0; i < min_size; i++) {
        delete min_heap[i];
        delete max_heap[i];
    }
}

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        int N, M;
        char cmd;
        cin >> N;
        for (int i = 0; i <= 1000000; i++) {
            min_heap[i] = max_heap[i] = nullptr;
        }
        min_size = max_size = 0;
        for (int i = 0; i < N; i++) {
            cin >> cmd >> M;
            if (cmd == 'I') {
                insert_node(M);
            } else {
                remove_node(M);
            }
        }

        if (min_size == 0) {
            cout << "EMPTY\n";
        } else {
            cout << max_heap[1]->elem << ' ' << min_heap[1]->elem << '\n';
        }

        release();
    }
}
