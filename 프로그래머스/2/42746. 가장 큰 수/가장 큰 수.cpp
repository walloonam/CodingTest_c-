#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> a;
    for (int i = 0;i < numbers.size(); i++) {
        a.push_back(to_string(numbers[i]));

    }

    sort(a.begin(), a.end(), compare);

    if (a[0] == "0") {
        return "0";
    }

    for (int i= 0; i < a.size();i++) {
        answer = answer + a[i];
    }


    return answer;
}