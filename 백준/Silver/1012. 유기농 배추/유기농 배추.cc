#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(int x, int y, vector<vector<int>>& field, vector<vector<bool>>& visited) {
    static const int dx[] = { -1, 1, 0, 0 };
    static const int dy[] = { 0, 0, -1, 1 };
    visited[x][y] = true;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < field.size() && ny >= 0 && ny < field[0].size() && field[nx][ny] == 1 && !visited[nx][ny]) {
            dfs(nx, ny, field, visited);
        }
    }
}







int countCabbageClusters(vector<vector<int>>& field) {
    int countCabbage = 0;
    vector<vector<bool>> visited(field.size(), vector<bool>(field[0].size(), false));
    
    for (int i = 0; i < field.size();i++) {
        for (int j = 0; j < field[0].size();j++) {
            if (field[i][j] == 1 && !visited[i][j]) {
                dfs(i, j, field, visited);
                countCabbage++;
            }
        }
    }

    return countCabbage;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int M, N, K;
        cin >> M >> N >> K;

        vector<vector<int>> field(M, vector<int>(N, 0));

        for (int k = 0; k < K; ++k) {
            int X, Y;
            cin >> X >> Y;
            field[X][Y] = 1;
        }

        int result = countCabbageClusters(field);
        cout << result << endl;
    }

    return 0;
}
