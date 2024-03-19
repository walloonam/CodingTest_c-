#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> money) {
    const int MOD = 1000000007;
    vector<int> dp(n + 1, 0); // dp[i]는 금액 i를 만드는 방법의 수를 저장합니다.
    dp[0] = 1; // 초기값 설정: 금액 0을 만드는 방법은 하나뿐입니다.
    
    // 각 동전을 한 번씩 사용하여 dp 배열을 갱신합니다.
    for (int coin : money) {
        for (int i = coin; i <= n; ++i) {
            dp[i] += dp[i - coin];
            dp[i] %= MOD; // 값이 MOD로 나눈 나머지를 저장합니다.
        }
    }
    
    return dp[n];
}