#include <bits/stdc++.h>
using namespace std;
int tar;

bool check(int x) {
    if (x == tar) return true;
    else return false;
}

int search(int l, int r) {
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    int l, r;
    cin >> l >> r >> tar;
    cout << search(l, r) << endl;
    return 0;
}