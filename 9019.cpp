// 단순 BFS로 풀었는데 string 연결 때문에 시간이 많이 걸리는것 같다.

#include <iostream>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

typedef tuple<int, int, string> Tuple;

int D(int n) {
    return (2 * n) % 10000;
}

int S(int n) {
    if (n == 0) {
        return 9999;
    }
    return n - 1;
}

int L(int n) {
    return (n * 10 + n / 1000) % 10000;
}

int R(int n) {
    return n / 10 + n % 10 * 1000;
}

string bfs(int n, int m) {
    queue<Tuple> queue;
    queue.emplace(n, m, "");
    bool visited[10000] = {false};
    while (!queue.empty()) {
        Tuple tuple = queue.front();
        queue.pop();
        n = get<0>(tuple);
        m = get<1>(tuple);
        string count = get<2>(tuple);
        if (n == m) {
            return count;
        }
        // 4개 행위의 결과를 추가

        if (!visited[D(n)]) {
            visited[D(n)] = true;
            queue.emplace(D(n), m, count + 'D');
        }
        if (!visited[S(n)]) {
            visited[S(n)] = true;
            queue.emplace(S(n), m, count + 'S');
        }
        if (!visited[L(n)]) {
            visited[L(n)] = true;
            queue.emplace(L(n), m, count + 'L');
        }
        if (!visited[R(n)]) {
            visited[R(n)] = true;
            queue.emplace(R(n), m, count + 'R');
        }
    }
    return "";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t-- > 0) {
        int N, M;
        cin >> N >> M;
        cout << bfs(N, M) << '\n';
    }
}
