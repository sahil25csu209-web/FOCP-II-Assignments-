#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000000;

int spf[MAXN + 1];   // smallest prime factor
int distinctPrimeCount[MAXN + 1];

void sieve() {
    for (int i = 1; i <= MAXN; i++) spf[i] = i;

    for (int i = 2; i * i <= MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAXN; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    // count distinct prime factors
    distinctPrimeCount[1] = 0;

    for (int i = 2; i <= MAXN; i++) {
        int x = i;
        int count = 0;
        int last = -1;

        while (x > 1) {
            int p = spf[x];
            if (p != last) count++;
            last = p;
            x /= p;
        }

        distinctPrimeCount[i] = count;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int k = distinctPrimeCount[n];
        cout << (1 << k) << '\n';  // 2^k
    }

    return 0;
}