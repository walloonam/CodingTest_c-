#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;

const int N = 751;
int r, c;
char MAP[N][N];
int dp_up[2][N][N], dp_down[2][N][N]; // 0 오른쪽, 1 왼쪽


int go_up(int x, int y, int val) {
    if (x < 0 || x >= r || y < 0 || y >= c || MAP[x][y] == '0') return 0;

    int& ret = dp_up[1][x][y];
    if (ret != -1) return ret;

    dp_up[0][x][y] = val;

    return ret = 1 + go_up(x + 1, y - 1, val + 1);
}

int go_down(int x, int y, int val) {
    if (x < 0 || x >= r || y < 0 || y >= c || MAP[x][y] == '0') return 0;

    int& ret = dp_down[0][x][y];
    if (ret != -1) return ret;

    dp_down[1][x][y] = val;

    return ret = 1 + go_down(x + 1, y + 1, val + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(dp_up, -1, sizeof(dp_up));
    memset(dp_down, -1, sizeof(dp_down));

    cin >> r >> c;
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) cin >> MAP[i][j];


    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) {
        if (MAP[i][j] == '1') {
            go_up(i, j, 1); go_down(i, j, 1);
        }
    }

    int ans = 0;
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) {
        int x = min(dp_up[0][i][j], dp_down[0][i][j]);
        if (MAP[i][j] == '1') {
            for (int len = 1; len <= x; len++) {
                int k = j + 2 * len - 2;

                if (k >= c) break;
                if (MAP[i][k] == '0') continue;

                int y = min(dp_up[1][i][k], dp_down[1][i][k]);
                if (y >= len) ans = max(ans, len);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
