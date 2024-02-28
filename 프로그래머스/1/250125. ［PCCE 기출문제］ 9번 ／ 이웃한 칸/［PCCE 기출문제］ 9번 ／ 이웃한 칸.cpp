#include <string>
#include <vector>

using namespace std;
int answer = 0;


void check(vector<vector<string>> board, int len, int h, int w) {
    int dh[4] = {1,0,-1,0};  //상우하좌
    int dw[4] = {0,1,0,-1};
    for (int i = 0; i <= 3; i++) {
        int nh = h + dh[i];
        int nw = w + dw[i];
        if (nh >= 0 && nw >= 0 && nh < len && nw < len) {
            if (board[h][w] == board[nh][nw]) {
                answer++;
            }
        }
    }
}


int solution(vector<vector<string>> board, int h, int w) {
    int len = board.size();
    check(board, len, h, w);
    return answer;

}