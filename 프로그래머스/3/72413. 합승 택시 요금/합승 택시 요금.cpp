#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <iostream>

using namespace std;

const int INF = 2000000000;

vector<vector<pair<int, int>>> graph;

void dijkstra(int start, vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start });
    dist[start] = 0;

    while (!pq.empty()) {
        int cur_node = pq.top().second;
        int cur_dist = pq.top().first;
        cout << pq.top().second <<" : " <<pq.top().first<<endl;
        pq.pop();
        

        if (dist[cur_node] < cur_dist) continue;

        for (auto& neighbor : graph[cur_node]) {
            int next_node = neighbor.first;
            int next_dist = cur_dist + neighbor.second;

            if (dist[next_node] > next_dist) {
                dist[next_node] = next_dist;
                pq.push({ next_dist, next_node });
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    graph.resize(n + 1);

    for (auto& fare : fares) {
        int from = fare[0], to = fare[1], cost = fare[2];
        graph[from].push_back({ to, cost });
        graph[to].push_back({ from, cost });
    }

    vector<int> s_dist(n + 1, INF);
    vector<int> a_dist(n + 1, INF);
    vector<int> b_dist(n + 1, INF);

    dijkstra(s, s_dist);
    dijkstra(a, a_dist);
    dijkstra(b, b_dist);

    for (int i = 1; i <= n; ++i) {
        answer = min(answer, s_dist[i] + a_dist[i] + b_dist[i]);
    }

    return answer;
}
