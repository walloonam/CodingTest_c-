#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>


using namespace std;


int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int>index;
    long long sum = 0;
    int bit = 1;
    for (int i = 0; i < want.size();i++) {
        index[want[i]] = bit;
        sum = sum + bit * number[i];
        cout << bit << endl;
        bit = bit * 10;
    }
    long long total = 0;
    for (int i = 0; i < 10;i++) {
        total += index[discount[i]];
    }
    if (total == sum) {
        answer++;
    }

    for (int i = 10; i < discount.size();i++) {
        total -= index[discount[i - 10]];
        total += index[discount[i]];
        if (total == sum) {
            answer++;
        }
    }

    return answer;
}