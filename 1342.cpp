/*
어느 위치를 선택하면 그 위치의 수를 포함한 K개의 수들은 서로 순서를 뒤집음

정해진 규칙이 있는게 아니라, 그냥 완전 탐색아닐까? 2<=K<=N<=8 이니까...
한 번에 한 개의 숫자만 옮기려고 하는 것이 아닐 때가 있는듯
정렬이 완료된 원소는 건드리지 않음?
가능한 최소의 수를 찾는 것이므로, dfs를 쓰면 최소의 수가 아닐 수 있음
bfs를 쓰면 가지치기는..? 불가능한 경우 역시 있기 때문에 큐가 비는 경우를 만들어야함
8 4
7 2 1 6 8 4 3 5
그래프가 왜 필요할까? 어떻게 하다보니 이미 만들어진 순열로 가게 되는 경우?
 */

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int N, K;

class Node {
public:
    int list[8];
    int count;

    Node(int count) {
        this->count = count;
    }
};

vector<Node> list;
queue<Node> q;
map<int, Node> m;

int KEY(int *list) {
    int k = 0;
    for (int i = 0; i < N; i++) {
        k = k * 10 + list[i];
    }
    return k;
}

bool CHECK(int *l) {
    for (int i = 0; i < N; i++) {
        if (l[i] != i + 1) {
            return false;
        }
    }
    return true;
}

void COPY_AND_SWAP(int *from, int *to, int s, int e) {
    for (int i = 0; i < N; i++) {
        to[i] = from[i];
    }
    while (s < e) {
        int t = to[s];
        to[s++] = to[e];
        to[e--] = t;
    }
}

void print(Node *node) {
    for (int i = 0; i < N; i++) {
        cout << node->list[i] << ' ';
    }
    cout << '\n';
}

int bfs() {
    while (!q.empty()) {
        Node node = q.front();
        if (CHECK(node.list)) {
            return node.count;
        }
        q.pop();
        for (int i = 0; i <= N - K; i++) {
            Node next(node.count + 1);
            COPY_AND_SWAP(node.list, next.list, i, i + K - 1);
            int key = KEY(next.list);
            auto iter = m.find(key);
            if (iter == m.end()) {
                q.emplace(next);
                m.emplace(key, next);
            }
        }
    }
    return -1;
}

int main() {
    cin >> N >> K;
    Node node(0);
    for (int i = 0; i < N; i++) {
        cin >> node.list[i];
    }
    q.emplace(node);
    cout << bfs();
}
