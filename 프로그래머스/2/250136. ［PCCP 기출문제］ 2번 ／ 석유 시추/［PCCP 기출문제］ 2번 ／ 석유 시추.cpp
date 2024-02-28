#include <string>
#include <vector>

using namespace std;
vector<vector<bool>> checkland;
vector<int> result;
vector<bool> xs;
int count1;

void bfs(vector<vector<int>>& land, int len, int y, int x) {
    int dy[4] = { 1,0,-1,0 };  //상 우 하 좌
    int dx[4] = { 0,1,0,-1 };
    count1++;
    checkland[y][x] = false;
    xs[x] = true;
    for (int i = 0; i < 4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < land[0].size() && ny < land.size() && checkland[ny][nx] && land[ny][nx]) {
            bfs(land, len, ny, nx);
        }

    }


}


int solution(vector<vector<int>> land) {
    int len = land[0].size();
    checkland = vector<vector<bool>>(land.size(), vector<bool>(len, true)); // checkland 초기화
    result = vector<int>(len, 0); // result 초기화

    for (int i = 0;i < land.size();i++) {
        for (int j = 0; j < len;j++) {
            if (land[i][j] && checkland[i][j]) {
                count1 = 0;
                xs = vector<bool>(len, false); // xs 초기화
                bfs(land, len, i, j);
                for (int a=0; a < len;a++) {
                    if (xs[a]) {
                        result[a] += count1;
                    }
                }
            }

        }
    }
    int answer = 0;
    for (int i = 0; i < len;i++) {
        answer = max(answer, result[i]);
    }
    return answer;
}