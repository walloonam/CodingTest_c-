#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {

    vector<int> answer;

    int a = 1;
    while (true) {
        if (yellow % a == 0) {
            int x = (yellow / a)+2;
            int y = a+2;
            int sum = x * 2 + a * 2;
            if (sum == brown) {
                answer.push_back(x);
                answer.push_back(y);
                break;
            }
        }

        a++;
    }

    return answer;
}