#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    // For each movie, store users who booked it
    unordered_map<int, unordered_set<int>> bookings;

    while (Q--) {
        string query;
        cin >> query;

        // ---------------- BOOK ----------------
        if (query == "BOOK") {
            int userID, movieID;
            cin >> userID >> movieID;

            // If already booked OR movie is full
            if (bookings[movieID].count(userID) > 0) {
                cout << "false\n";
            }
            else if (bookings[movieID].size() >= 100) {
                cout << "false\n";
            }
            else {
                bookings[movieID].insert(userID);
                cout << "true\n";
            }
        }

        // ---------------- CANCEL ----------------
        else if (query == "CANCEL") {
            int userID, movieID;
            cin >> userID >> movieID;

            // If user has not booked
            if (bookings[movieID].count(userID) == 0) {
                cout << "false\n";
            }
            else {
                bookings[movieID].erase(userID);
                cout << "true\n";
            }
        }

        // ---------------- IS_BOOKED ----------------
        else if (query == "IS_BOOKED") {
            int userID, movieID;
            cin >> userID >> movieID;

            if (bookings[movieID].count(userID) > 0) {
                cout << "true\n";
            } else {
                cout << "false\n";
            }
        }

        // ---------------- AVAILABLE_TICKETS ----------------
        else if (query == "AVAILABLE_TICKETS") {
            int movieID;
            cin >> movieID;

            int available = 100 - bookings[movieID].size();
            cout << available << "\n";
        }
    }

    return 0;
}