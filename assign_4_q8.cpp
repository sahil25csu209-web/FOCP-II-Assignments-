#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    string name;

    cout << "Enter your name: ";
    cin >> name;

    // Roast templates
    string roasts[] = {
        name + ", you write code so slow that even a turtle switched to Python.",
        name + ", if procrastination were an Olympic sport, you'd win gold.",
        name + ", your code has more bugs than a jungle.",
        name + ", even Google can't debug your logic.",
        name + ", your brain uses Internet Explorer speed.",
        name + ", you press run and pray instead of debugging.",
        name + ", your code works... only in your imagination."
    };

    int n = sizeof(roasts) / sizeof(roasts[0]);

    srand(time(0)); // random seed

    char choice;
    do {
        int index = rand() % n;
        cout << roasts[index] << endl;

        cout << "Want another roast? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Enough roasting for today 😎" << endl;

    return 0;
}