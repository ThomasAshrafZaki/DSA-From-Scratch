#ifndef QUICK_VOCAB_HPP
#define QUICK_VOCAB_HPP

#include "vector.hpp"
#include <string>
#include <fstream>
#include <iostream>

// This class is used to manage a vocabulary list (like a mini dictionary)
class quick_vocab {
private:
    // A dynamic array (custom vector) to store words
    vector<string>* words {nullptr};

public:
    // Constructor: used to initialize the object
    quick_vocab();

    // Read words from a text file and insert them into the list
    void insert_words_by_text();

    // Insert a single word (entered by the user)
    void insert_words_by_yourself(const string& word);

    // Print all the words stored
    void print_words();

    // Find and print all words that start with a given prefix
    void find_words_start_with(const string& word);

    // Find and print all positions of a specific word
    void find_word(const string& word);

    // Keep asking user to search for words (interactive mode)
    void find_word_interactive();

    // Return the total number of words stored
    int count_word();

    // Remove a word from the list (by value)
    void remove_word(const string& word);

    // Destructor: free the memory used
    ~quick_vocab();
};

#endif
