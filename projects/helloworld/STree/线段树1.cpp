#include <bits/stdc++.h>
using namespace std;

int n, m, a[500001], f[2000001];

inline void buildtree(int k, int l, int r) {
    if (l == r) {
        f[k] = a[l];
        return;
    }
    int m = (l + r) >> 1;
    buildtree(2 * k, l, m);
    buildtree(2 * k + 1, m + 1, r);
    f[k] = f[2 * k] + f[2 * k + 1];
}

inline void add(int k, int l, int r, int x, int y) {
    f[k] += y;
    if (l == r)
        return;
    int m = (l + r) >> 1;
    if (x <= m) 
        add(2 * k, l, m, x, y);
    else
        add(2 * k + 1, m + 1, r, x, y);
}

int calc(int k , int l, int r, int s, int t) {
    if (l == s && r == t)
        return f[k];
    int m = (l + r) >> 1;
    if (t <= m)
        return calc(2 * k, l, m, s, t);
    else if (s > m)
        return calc(2 * k + 1, m + 1, r, s, t);
    else
        return calc(2 * k, l, m, s, m) + calc(2 * k + 1, m + 1, r, m + 1, t);
}
int main() {
    freopen("C:\\coding\\projects\\helloworld\\in.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    buildtree(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1)
            add(1, 1, n, x, y);
        else
            cout << calc(1, 1, n, x, y) << endl;
    }
    fclose(stdin);
    return 0;
}

/*
luogu:P3374

input:
5 5
1 5 4 2 3
1 1 3
2 2 5
1 3 -1
1 4 2
2 1 4

output:
14
16
*/