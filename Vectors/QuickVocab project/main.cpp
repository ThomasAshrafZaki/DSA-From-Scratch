#include "quick_vocab.hpp"
#include <iostream>
using namespace std;

int main() {
    quick_vocab qv;
    int choice;
    string input;

    while (true) {
        cout << "\n======= QuickVocab Menu =======\n";
        cout << "1. Insert words from file\n";
        cout << "2. Insert a word manually\n";
        cout << "3. Print all words\n";
        cout << "4. Find words starting with a prefix\n";
        cout << "5. Find a word (by exact match)\n";
        cout << "6. Find a word (interactive)\n";
        cout << "7. Count words\n";
        cout << "8. Remove a word\n";
        cout << "9. Exit\n";
        cout << "Enter your choice (1-9): ";
        cin >> choice;

        switch (choice) {
            case 1:
                qv.insert_words_by_text();
                break;
            case 2:
                cout << "Enter word to insert: ";
                cin >> input;
                qv.insert_words_by_yourself(input);
                break;
            case 3:
                qv.print_words();
                break;
            case 4:
                cout << "Enter prefix: ";
                cin >> input;
                qv.find_words_start_with(input);
                break;
            case 5:
                cout << "Enter word to search: ";
                cin >> input;
                qv.find_word(input);
                break;
            case 6:
                qv.find_word_interactive();
                break;
            case 7:
                cout << qv.count_word() << endl;
                break;
            case 8:
                cout << "Enter word to remove: ";
                cin >> input;
                qv.remove_word(input);
                break;
            case 9:
                cout << "Exiting the program...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
