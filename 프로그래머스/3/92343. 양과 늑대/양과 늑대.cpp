#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int sheepCount, int wolfCount, vector<bool>& visited, vector<int>& info, vector<vector<int>>& edges, int& answer) {
    // Back Tracking 조건 (양이 잡아먹힘)
    if (sheepCount <= wolfCount)
        return;

    // 최대 값이라면 갱신
    answer = max(answer, sheepCount);

    // 모든 노드를 순회하여 갈 수 있는 노드를 찾음
    for (int i = 0; i < edges.size(); i++) {
        int parentIndex = edges[i][0];
        int childIndex = edges[i][1];

        // 현재 갈 수 있는 노드인 경우
        if (visited[parentIndex] && !visited[childIndex]) {
            visited[childIndex] = true;

            if (info[childIndex] == 0)
                DFS(sheepCount + 1, wolfCount, visited, info, edges, answer);
            else
                DFS(sheepCount, wolfCount + 1, visited, info, edges, answer);

            visited[childIndex] = false;
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    vector<bool> visited(info.size(), false); // 방문배열

    // 초기 값 세팅
    visited[0] = true;

    // DFS 탐색 ( 초기 값은 최상위 노드를 탐색한 상태로 시작 )
    DFS(1, 0, visited, info, edges, answer);

    return answer;
}