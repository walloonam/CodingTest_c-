#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> result;
    vector<int> a;
    int count = 0;
    for (int i = 0; i < clothes.size();i++) {
        if (result.find(clothes[i][1]) != result.end()) {
            a[result[clothes[i][1]]]++;
        }
        else {
            result.insert({ clothes[i][1],count });
            a.push_back(1);
            count++;
        }
    }
    for (int i = 0; i < a.size();i++) {
        answer = answer * (a[i] + 1);
    }
    answer = answer - 1;
    return answer;
}