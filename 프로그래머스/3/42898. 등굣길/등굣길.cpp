#include <iostream>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // 물에 잠긴 지역 표시
    for (const auto& puddle : puddles)
        dp[puddle[1]][puddle[0]] = -1;

    // 시작점 초기화
    dp[1][1] = 1;

    // 경로 개수 갱신
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i == 1 && j == 1)
                continue;
            if (dp[i][j] == -1) // 물에 잠긴 지역은 0으로 초기화
                dp[i][j] = 0;
            else
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
        }
    }

    return dp[n][m];
}