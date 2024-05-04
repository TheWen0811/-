#include<iostream>
using namespace std;

const int MAXC = 105;
const int MAXN = 10005;
double dp[MAXC][MAXN];
int C, N, M;

int main() {
    cin >> C >> N >> M;
    dp[0][0] = 1.0; // 初始状态：没取到巧克力时桌子上已有0块巧克力的概率为1
    for (int i = 1; i <= C; i++) { // i表示当前取出的巧克力的颜色
        for (int j = 0; j <= N; j++) { // j表示当前取出的巧克力的数量
            dp[i][j] += dp[i - 1][j]; // 如果不取当前颜色的巧克力，概率不变
            if (j >= 1) dp[i][j] += dp[i - 1][j - 1] * (j - 1); // 如果取当前颜色的巧克力，要排除已经有的巧克力，剩下j-1块，有j-1种位置放新取的巧克力
        }
    }
    double sum = 0;
    for (int j = M; j <= N; j++) sum += dp[C][j]; // 统计最后桌子上有m块的概率
    printf("%.3f\n", sum);
    return 0;
}