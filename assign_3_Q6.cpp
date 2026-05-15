#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    // userID -> balance
    unordered_map<int, long long> balance;

    while (Q--) {
        string query;
        cin >> query;

        // ---------------- CREATE ----------------
        if (query == "CREATE") {
            int userID;
            long long amount;
            cin >> userID >> amount;

            if (balance.count(userID) == 0) {
                // new user
                balance[userID] = amount;
                cout << "true\n";
            } else {
                // already exists → just add money
                balance[userID] += amount;
                cout << "false\n";
            }
        }

        // ---------------- DEBIT ----------------
        else if (query == "DEBIT") {
            int userID;
            long long amount;
            cin >> userID >> amount;

            if (balance.count(userID) == 0 || balance[userID] < amount) {
                cout << "false\n";
            } else {
                balance[userID] -= amount;
                cout << "true\n";
            }
        }

        // ---------------- CREDIT ----------------
        else if (query == "CREDIT") {
            int userID;
            long long amount;
            cin >> userID >> amount;

            if (balance.count(userID) == 0) {
                cout << "false\n";
            } else {
                balance[userID] += amount;
                cout << "true\n";
            }
        }

        // ---------------- BALANCE ----------------
        else if (query == "BALANCE") {
            int userID;
            cin >> userID;

            if (balance.count(userID) == 0) {
                cout << -1 << "\n";
            } else {
                cout << balance[userID] << "\n";
            }
        }
    }

    return 0;
}