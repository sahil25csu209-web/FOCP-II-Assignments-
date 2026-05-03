#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    string name;

    cout << "Enter your name: ";
    cin >> name;

    // Excuse templates
    string excuses[] = {
        "Sorry " + name + ", my internet stopped working at the worst time.",
        "Sorry " + name + ", my laptop suddenly crashed while doing the assignment.",
        "Sorry " + name + ", there was a power cut in my area.",
        "Sorry " + name + ", I was not feeling well yesterday.",
        "Sorry " + name + ", I accidentally deleted my work.",
        "Sorry " + name + ", my files got corrupted.",
        "Sorry " + name + ", I had a family emergency.",
        "Sorry " + name + ", I forgot to save my work.",
        "Sorry " + name + ", my system updated unexpectedly.",
        "Sorry " + name + ", I was helping someone at home."
    };

    int n = sizeof(excuses) / sizeof(excuses[0]);

    srand(time(0)); // seed for randomness

    char choice;
    do {
        int index = rand() % n;
        cout << excuses[index] << endl;

        cout << "Generate another excuse? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "No more excuses 😄";

    return 0;
}