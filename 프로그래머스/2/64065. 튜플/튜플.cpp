#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {

    map<int, int> number;

    string num ="";
    bool count = false;
    for (int i = 1;i < s.length()-1;i++) {
        if (s[i] == '{') {
            num = "";
            count = true;
        }
        else if (s[i] == '}') {
            int num1;
            num1 = stoi(num);
            number[num1] += 1;
            num = "";
            count = false;

        }
        else if (s[i] == ',' &&count) {
            int num1;
            num1 = stoi(num);
            number[num1] += 1;
            num = "";

        }
        else {
            num += s[i];
        }
    }

    vector<pair<int,int>> vec(number.begin(), number.end());

    sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;  // 두 번째 값(value)를 기준으로 오름차순 정렬
        });


    vector<int> answer;

    for (auto& ans : vec) {
        answer.push_back(ans.first);
    }

    return answer;
}