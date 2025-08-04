
# QuickVocab

> A simple C++ project to manage and explore vocabulary words using a custom vector implementation.

##  Overview

QuickVocab is a C++ command-line application that allows users to manage a collection of vocabulary words. It is designed to help with learning and managing word lists efficiently. It supports word insertion, searching, deletion, and more — all built on top of a custom `vector` class (not STL).

This project was built as part of a deeper understanding of data structures, particularly dynamic arrays (vectors), and it will serve as a base for more advanced DSA-related projects.

##  Features

- Load words from a `.txt` file into memory
- Manually insert words
- Print all words stored
- Find a specific word
- Find all words starting with a prefix
- Remove a specific word
- Count total number of stored words
- Interactive search interface

##  Class Design

### `class quick_vocab`

Handles word management:

- `insert_words_by_text()` — reads words from `words.txt` and loads them
- `insert_words_by_yourself(word)` — allows user to add a single word
- `print_words()` — prints all stored words
- `find_word(word)` — finds all occurrences of a word and prints their indices
- `find_words_start_with(prefix)` — finds and prints all words with a given prefix
- `find_word_interactive()` — prompts user to enter a word and performs search
- `count_word()` — returns number of words stored
- `remove_word(word)` — removes all instances of a given word

### `vector<arrType>`

A basic generic dynamic array class with support for:

- Adding elements (`push_back`)
- Deleting elements at a specific index (`delete_val`)
- Finding value indices (`find_indices`)
- Printing all values (`print`)
- Getting value at index (`get_val`)
- Returning current size (`get_size`)

This helps reinforce understanding of dynamic memory management, templates, and class design in C++.

##  How to Use

1. Make sure you have a `words.txt` file in the same directory (optional).
2. Compile the project using g++:

```bash
g++ -o quick_vocab main.cpp quick_vocab.cpp -std=c++11
```

3. Run the app:

```bash
./quick_vocab
```

4. Follow the menu and interact with the app.

##  Future Additions

- Save updated words back to file
- Sort the words alphabetically
- Load/save using JSON or CSV
- Create GUI version using Qt or another library

##  Purpose

This project is not just about vocabulary — it's a **data structure learning exercise**. The goal is to **implement, use, and understand vectors deeply**, and to apply OOP principles practically. It's the **first** in a series of projects that reflect deep DSA knowledge and readiness for real-world software tasks.

##  Author

Made with care by "Thomas Ashraf Zaki" as part of the DSA study and project series.
