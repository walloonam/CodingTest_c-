#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++) {
        int begin = commands[i][0] - 1;
        int end = commands[i][1];
        int index = commands[i][2] - 1;
        int sub = end - begin;
        vector<int> a(array.begin() + begin, array.begin() + end);
        sort(a.begin(), a.end());
        answer.push_back(a[index]);
    }

    return answer;
}
