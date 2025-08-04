#include "quick_vocab.hpp"
using namespace std;

// Constructor: displays welcome message and initializes the words vector
quick_vocab::quick_vocab() {
    cout << "Hi in the QuickVocab app \n";
    words = new vector<string> {};
}

// Insert words from a file named "words.txt"
void quick_vocab::insert_words_by_text() {
    ifstream file("words.txt");
    string word;
    
    if (!file.is_open()) {
        cout << "No file add \n"; // file not found
    } else {
        // Read words one by one from the file and store them
        while (file >> word) {
            words->push_back(word);
        }
        file.close();
    }
}

// Destructor: releases the memory used by words vector
quick_vocab::~quick_vocab() {
    delete words;
}

// Add a single word to the list
void quick_vocab::insert_words_by_yourself(const string& word) {
    words->push_back(word);
}

// Print all stored words
void quick_vocab::print_words() {
    if (words != nullptr) {
        words->print();
    } else {
        cout << "No words to display.\n";
    }
}

// Find and print all words that start with the given prefix
void quick_vocab::find_words_start_with(const string& word) {
    cout << "\n the words is : ";
    bool check = false;

    for (int i = 0; i < words->get_size(); i++) {
        string current = words->get_val(i);
        
        // Check if current word starts with the prefix using compare()
        if (current.size() >= word.size() && !(current.compare(0, word.size(), word))) {
            cout << "[ " << current << " ]" << " ";
            check = true;
        }
    }

    if (!check) {
        cout << "[]";
    }

    cout << endl;
}

// Search for a specific word and print its positions (using vector's method)
void quick_vocab::find_word(const string& word) {
    if (words != nullptr) {
        words->find_indices(word);
    } else {
        cout << "No words to display.\n";
    }
}

// Ask user to enter a word, then search for it
void quick_vocab::find_word_interactive() {
    string w;
    cout << "Enter word to search: ";
    cin >> w;
    find_word(w);
}

// Return the number of stored words
int quick_vocab::count_word() {
    cout << endl << "nums of words = ";
    return words->get_size();
}

// Remove all instances of the given word from the list
void quick_vocab::remove_word(const string& word) {
    for (int i = 0; i < words->get_size(); ) {
        if (words->get_val(i) == word) {
            words->delete_val(i); // Don't increment i, because the list shrinks
        } else {
            i++;
        }
    }
}
