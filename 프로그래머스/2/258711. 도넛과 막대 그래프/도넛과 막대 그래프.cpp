#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    
    int donut = 0, stick = 0, eight = 0, bridge = 0;
    int maxNode=0;
    int sum = 0;
    vector<int> direction(1000000);
    vector<vector<int>> OutIn(1000000,vector<int>(2,0));

    for (const vector<int>& edge : edges) {
        direction[edge[0]] = edge[1];
        OutIn[edge[0]][0]++;
        OutIn[edge[1]][1]++;
        if (edge[0] > edge[1]) {
            if (edge[0] > maxNode)
                maxNode = edge[0];
        }
        else {
            if (edge[1] > maxNode)
                maxNode = edge[1];
        }
    }

    for (int i = 1; i <= maxNode;i++) {
        if (OutIn[i][0] >= 2 && OutIn[i][1] == 0) {
            bridge = i;
            sum = OutIn[i][0];
        }
        else if (OutIn[i][0] == 2 && OutIn[i][1] >= 2) {
            eight++;
        }
        else if (OutIn[i][0] == 0 && OutIn[i][1] >= 1) {
            stick++;
        }

    }
    donut = sum - stick - eight;
    vector<int> answer;
    answer.push_back(bridge);
    answer.push_back(donut);
    answer.push_back(stick);
    answer.push_back(eight);

    return answer;
}