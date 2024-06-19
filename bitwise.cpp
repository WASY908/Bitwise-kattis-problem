#include <iostream>
#include <vector>
#include <array>
using namespace std;

int n, k;
vector<int> a;

bool can(int x) {
    int bm = 0;
    for (int offset = 0; offset < n; ++offset) {
        if ((a[offset] & bm) == a[offset]) {
            continue;
        }
        bm |= a[offset];
        int sec = 0;
        int b = 0;
        for (int pos = offset + 1; pos < offset + 1 + n; ++pos) {
            b |= a[pos % n];
            if ((x & b) == x) {
                b = 0;
                ++sec;
            }
            if (sec >= k) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ans = 0;

    for (int i = 30; i >= 0; --i) {
        int b = 1 << i;
        if (can(ans | b)) {
            ans |= b;
        }
    }

    cout << ans << endl;

    return 0;
}
