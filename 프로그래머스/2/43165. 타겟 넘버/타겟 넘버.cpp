#include <string>
#include <vector>
#include <iostream>

using namespace std;
int count1 = 0;


void re(vector<int> numbers, int target, int index, int sum) {
    if (index == numbers.size()) {
        if (sum == target) {
            count1++;
        }
    }
    else {
        re(numbers, target, index + 1, sum + numbers[index]);
        re(numbers, target, index + 1, sum - numbers[index]);
    }
}


int solution(vector<int> numbers, int target) {
    re(numbers, target, 0, 0);
    return count1;
}