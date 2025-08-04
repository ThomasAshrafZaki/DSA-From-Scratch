#ifndef VECTOR_HPP
#define VECTOR_HPP

// Template class for a dynamic vector
// arrType is the data type of elements stored

template <typename arrType>
class vector {
    private :
        arrType * arr {nullptr}; // pointer to dynamic array
        int size {0};           // current number of elements
        int capacity {0};       // total allocated capacity
    public :
        vector () ; // default constructor
        vector (int size_v) ; // constructor with initial size
        void push_back (arrType val); // add value at the end
        void insert_val (int index , arrType val); // insert at index
        void delete_val (int index); // delete at index
        void set_val(int index , arrType val); // update value at index
        void extend_capacity(); // increase capacity
        arrType get_val (int index); // get value at index
        arrType find_first_index (arrType val); // find first index of value
        void find_indices (arrType val); // print all indices of value
        void print () const; // print all elements
        int get_size (); //get_size 
        ~vector(); // destructor
};

#include "vector.tpp"
#endif
