#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

int n;
bool visited[12]; // Assuming n is at most 12
vector<vector<int>> diceComb;

vector<int> scoreA;
vector<int> scoreB;

void combDice(int index, vector<int>& dices, vector<vector<int>>& originDices, int sum, vector<int>& team) {
    if (index == dices.size()) {
        team.push_back(sum);
        return;
    }

    for (int i = 0; i < 6; i++) {
        combDice(index + 1, dices, originDices, sum + originDices[dices[index]][i], team);
    }
}

void permutation(int depth, int index, vector<int>& arr) {
    if (depth == n / 2) {
        diceComb.push_back(arr);
        return;
    }

    for (int i = index; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            arr[depth] = i;
            permutation(depth + 1, i + 1, arr);
            visited[i] = false;
        }
    }
}

vector<int> solution(vector<vector<int>> dice) {
    n = dice.size();
    vector<int> answer(n / 2, 0);

    fill(visited, visited + n, false);
    diceComb.clear();

    // 1. A가 뽑을 수 있는 주사위 조합 구하기
    vector<int> temp(n / 2);
    permutation(0, 0, temp);

    // 2. 주사위 조합 별로 승률 계산
    int max = 0;
    for (vector<int>& combA : diceComb) {
        vector<int> combB(n / 2, 0);
        vector<bool> other(n, false);

        int index = 0;
        for (int choice : combA) {
            other[choice] = true;
        }

        for (int i = 0; i < other.size(); i++) {
            if (!other[i]) {
                combB[index] = i;
                index++;
            }
        }

        scoreA.clear(); // A가 선택한 주사위의 모든 조합
        scoreB.clear(); // B가 선택한 주사위의 모든 조합

        combDice(0, combA, dice, 0, scoreA);
        combDice(0, combB, dice, 0, scoreB);

        sort(scoreA.begin(), scoreA.end());
        sort(scoreB.begin(), scoreB.end());

        // 3. 이분탐색으로 승리 카운트 찾는다
        int totalWinCount = 0;

        for (int a : scoreA) {
            int left = 0;
            int right = scoreB.size();

            while (left + 1 < right) {
                int mid = (left + right) / 2;

                if (a > scoreB[mid]) {
                    left = mid;
                }
                else {
                    right = mid;
                }
            }

            totalWinCount += left;
        }

        if (totalWinCount > max) {
            max = totalWinCount;
            answer = combA;
        }
    }

    vector<int> answer2(n / 2, 0);
    if (n == 2) {
        return { answer[0] + 1 };
    }
    else {
        for (int i = 0; i < answer.size(); i++) {
            answer2[i] = answer[i] + 1;
        }
    }

    return answer2;
}