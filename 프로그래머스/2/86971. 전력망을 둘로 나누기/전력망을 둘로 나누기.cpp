#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

unordered_map<int, unordered_map<int, int>> tree;
unordered_map<int, bool> t;

int dfs(int start) {
    t[start] = true;
    int k = 0;
    for (auto& next_pair : tree[start]) {
        int next = next_pair.first;
        if (!t[next]) {
            int x = dfs(next) + 1;
            k += x;
            tree[start][next] = x;
        }
    }
    return k;
}

int solution(int n, vector<vector<int>> wires) {
    for (int i = 1; i <= n; ++i) {
        tree[i] = unordered_map<int, int>();
        t[i] = false;
    }

    for (auto& wire : wires) {
        tree[wire[0]][wire[1]] = 0;
        tree[wire[1]][wire[0]] = 0;
    }

    dfs(1);

    int answer = 101;
    for (auto& node_pair : tree) {
        int node = node_pair.first;
        for (auto& next_pair : node_pair.second) {
            int key = next_pair.first;
            int value = next_pair.second;
            answer = min(answer, abs(n - value*2));
        }
    }

    return answer;
}