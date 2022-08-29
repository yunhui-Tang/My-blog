#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

typedef pair<int, int> P;

//stdin
char maze[1000][1000 + 1];
int N, M;
int sx, sy, gx, gy;
int d[1000][2000];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int bfs() {
    queue<P> que;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) 
            d[i][j] = INF;
    que.push(P(sx, sy));
    d[sx][sy] = 0;

    while (que.size()) {
        P p = que.front();
        que.pop();
        if (p.first == gx && p.second == gy) break;

        for (int i = 0; i < 4; i++) {
            int nx = p.first + dx[i], ny = p.second + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '#' && d[nx][ny] == INF) {
                que.push(P(nx, ny));
            }
        }
    }
    return d[gx][gy];
}

int main() {
    cin >> N >> M;
    int ans = bfs();
    return 0;
}