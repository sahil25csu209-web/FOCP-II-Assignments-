#include <iostream>
#include <string>
using namespace std;

bool canTurnOff(string &s, int n, int k, int l) {
    int ops = 0;
    for (int i = 0; i < n; ) {
        if (s[i] == '1') {
            ops++;
            if (ops > k) return false;
            i += l; // skip l bulbs
        } else {
            i++;
        }
    }
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;

    string bulbs;
    cin >> bulbs;

    int left = 1, right = n, ans = n;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (canTurnOff(bulbs, n, k, mid)) {
            ans = mid;
            right = mid - 1; // try smaller l
        } else {
            left = mid + 1; // need bigger l
        }
    }

    cout << ans << endl;
    return 0;
}