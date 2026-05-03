#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        unordered_map<int,int> freq;

        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            freq[x]++;
        }

        vector<int> v;

        // each value can appear at most twice
        for (auto &p : freq) {
            int times = min(2, p.second);
            while (times--) v.push_back(p.first);
        }

        sort(v.rbegin(), v.rend());

        long long alex = 0, bob = 0;

        for (int i = 0; i < v.size(); i++) {
            if (i % 2 == 0) alex += v[i];
            else bob += v[i];
        }

        if (alex > bob) cout << "Alex\n";
        else cout << "Bob\n";
    }

    return 0;
}