#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int a[201][201], i, j, n, dp[201];
int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        for (j = i + 1; j <= n; j++) {
            cin >> a[i][j];
        }
        dp[i] = INF;
    }
    for (i = n - 1; i >= 1; i--) {
        for (j = i + 1; j <= n; j++) {
            dp[i] = min(dp[i], a[i][j] + dp[j]);
        } 
    }
    cout << dp[1];
    return 0;
}