#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

map<char, string> keymap;
vector<string> list;

string convert(const char *cmd, int j) {
    string str;
    int i = -1;
    while (cmd[++i]) {
        if (i == j) {
            str += '[';
            str += cmd[i];
            str += ']';
            continue;
        }
        str += cmd[i];
    }
    return str;
}

char lowercase(char c) {
    return c < 'a' ? c + 32 : c;
}

string shortcut(string cmd) {
    int j = 0;
    const char *str = cmd.c_str();
    while (j < cmd.size()) {
        if (j == 0 || str[j - 1] == ' ') {
            char c = str[j];
            if (keymap.find(lowercase(c)) == keymap.end()) {
                return keymap[lowercase(c)] = convert(str, j);
            }
        }
        j++;
    }
    j = 0;
    while (j < cmd.size()) {
        char c = str[j];
        if (c != ' ' && keymap.find(lowercase(c)) == keymap.end()) {
            return keymap[lowercase(c)] = convert(str, j);
        }
        j++;
    }
    return cmd;
}

int main() {
    int N;
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        string cmd;
        getline(cin, cmd);
        list.emplace_back(shortcut(cmd));
    }
    for (int i = 0; i < N; i++) {
        cout << list[i] << '\n';
    }
}
